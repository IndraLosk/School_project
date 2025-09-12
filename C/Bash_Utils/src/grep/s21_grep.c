#include "s21_grep.h"

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void init_opt(opt *options) {
  options->pattern = true;                        // -e
  options->ignor_up_lower_case = false;           // -i
  options->invert_match = false;                  // -v
  options->output_count = false;                  // -c
  options->output_matching = false;               // -l
  options->number_line = false;                   // -n
  options->matching_lines_without_files = false;  // -h
  options->suppress_error_messages = false;       // -s
  options->take_regexes = false;                  // -f
  options->matched_parts = false;                 // -o
}

void to_lowercase(char *str) {
  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

void last_n(char *str) {
  if (str[strlen(str) - 1] != '\n') {
    putchar('\n');
  }
}

void grep(FILE *file, char *search_word, int flag_count, char *file_name,
          bool pattern, bool ignor_up_lower_case, bool invert_match,
          bool output_count, bool output_matching, bool number_line,
          bool matching_lines_without_files, bool take_regexes,
          bool matched_parts, char **patterns, int pattern_count) {
  char *buffer = NULL;
  size_t buffer_size = 0;
  ssize_t line_size;

  bool match_found = false;
  int count_mutch_found = 0;
  int count_number_line = 0;

  regex_t regex;
  regmatch_t pmatch[1];

  if (regcomp(&regex, search_word, REG_EXTENDED) != 0) {
    fprintf(stderr, "Could not compile regex\n");
    return;
  }

  while ((line_size = getline(&buffer, &buffer_size, file)) != -1) {
    if (number_line) count_number_line++;
    match_found = false;

    if (take_regexes) {
      for (int i = 0; i < pattern_count; i++) {
        if (strstr(buffer, patterns[i]) != NULL) {
          match_found = true;
          break;
        }
      }
    } else if (pattern) {
      if (regexec(&regex, buffer, 1, pmatch, 0) == 0) {
        match_found = true;
      }
    } else {
      if (strstr(buffer, search_word) != NULL) {
        match_found = true;
      }
    }

    if (ignor_up_lower_case && !match_found) {
      char *buffer_lower = strdup(buffer);
      char *search_word_lower = strdup(search_word);

      to_lowercase(buffer_lower);
      to_lowercase(search_word_lower);

      if (pattern) {
        regex_t regex_lower;
        if (regcomp(&regex_lower, search_word_lower,
                    REG_EXTENDED | REG_ICASE) == 0) {
          if (regexec(&regex_lower, buffer_lower, 1, pmatch, 0) == 0) {
            match_found = true;
          }
          regfree(&regex_lower);
        }
      } else {
        if (strstr(buffer_lower, search_word_lower) != NULL) {
          match_found = true;
        }
      }

      free(buffer_lower);
      free(search_word_lower);
    }

    if (invert_match) {
      match_found = !match_found;
    }

    if (matched_parts && !output_count && !output_matching) {
      const char *ptr = buffer;
      bool not_v = true;
      while ((ptr = strstr(ptr, search_word)) != NULL) {
        if (!invert_match) {
          if (number_line) printf("%d:", count_number_line);
          fputs(search_word, stdout);
          printf("\n");
        }
        ptr += strlen(search_word);
        not_v = false;
      }
      if (invert_match && not_v) {
        fputs(buffer, stdout);
        last_n(buffer);
      }
    }

    // print
    if (match_found && !output_count && !output_matching && !matched_parts) {
      if (flag_count > 1 && !matching_lines_without_files)
        printf("%s:", file_name);
      if (number_line) printf("%d:", count_number_line);
      fputs(buffer, stdout);  // \n
      last_n(buffer);
    } else if (match_found) {
      count_mutch_found++;
    }
  }

  if (output_count) {
    if (flag_count > 1 && !output_matching)
      printf("%s:%d\n", file_name, count_mutch_found);
    else if (flag_count > 1 && output_matching && count_mutch_found != 0)
      printf("%s:1\n", file_name);
    else if (flag_count > 1 && output_matching)
      printf("%s:0\n", file_name);
    else if (output_matching && count_mutch_found != 0)
      printf("1\n");
    else if (output_matching)
      printf("0\n");
    else
      printf("%d\n", count_mutch_found);
  }

  if (output_matching && count_mutch_found) {
    printf("%s\n", file_name);
  }

  regfree(&regex);
  free(buffer);
}

int main(int argc, char *argv[]) {
  opt options;
  init_opt(&options);

  char *search_word = NULL;
  char *file_name = NULL;
  char *file_pattern_name = NULL;
  bool is_opt = true;
  int flag_count = 0;
  bool flag_e = false;
  bool flag_f = false;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && !flag_e && !flag_f) {
      flag_count++;
      for (int j = 1; argv[i][j] != '\0'; j++) {
        switch (argv[i][j]) {
          case 'e':
            flag_e = true;
            options.pattern = true;
            if (argv[i][j + 1] != '\0') {
              search_word = &argv[i][j + 1];
              j++;
              flag_count--;
            }
            break;
          case 'i':
            options.ignor_up_lower_case = true;
            break;
          case 'v':
            options.invert_match = true;
            break;
          case 'c':
            options.output_count = true;
            break;
          case 'l':
            options.output_matching = true;
            break;
          case 'n':
            options.number_line = true;
            break;
          case 'h':
            options.matching_lines_without_files = true;
            break;
          case 's':
            options.suppress_error_messages = true;
            break;
          case 'f':

            flag_f = true;
            options.take_regexes = true;
            if (argv[i][j + 1] != '\0') {
              search_word = &argv[i][j + 1];
              j++;
              flag_count--;
            }

            break;
          case 'o':
            options.matched_parts = true;
            break;
          default:
            printf("grep [options] template [file_name]\n");
            is_opt = false;
            break;
        }
        if (!is_opt) {
          break;
        }
      }
    } else {
      if (search_word == NULL) {
        if (options.take_regexes) {
          file_pattern_name = argv[i];
        }
        search_word = argv[i];
        flag_e = false;
      } else {
        file_name = argv[i];

        if (search_word == NULL || file_name == NULL) {
          printf("Usage: grep [options] template [file_name]\n");
          break;
        }

        FILE *file = fopen(file_name, "r");
        char **patterns = NULL;
        int pattern_count = 0;
        if (file == NULL) {
          if (!options.suppress_error_messages) {
            fprintf(stderr, "grep: %s: No such file or directory\n", file_name);
          }
        } else if (is_opt && !options.take_regexes) {
          int count_arg_no_flag = argc - flag_count - 2;
          grep(file, search_word, count_arg_no_flag, file_name, options.pattern,
               options.ignor_up_lower_case, options.invert_match,
               options.output_count, options.output_matching,
               options.number_line, options.matching_lines_without_files,
               options.take_regexes, options.matched_parts, NULL, 0);
          fclose(file);
        } else if (options.take_regexes && file_pattern_name != NULL) {
          FILE *file_pattern = fopen(file_pattern_name, "r");
          if (file_pattern == NULL) {
            if (!options.suppress_error_messages) {
              fprintf(stderr, "grep: %s: No such file or directory\n",
                      file_name);
            }
          }
          char *buffer = NULL;
          size_t buffer_size = 0;  // Начальный размер буфера
          ssize_t line_size;

          while ((line_size = getline(&buffer, &buffer_size, file_pattern)) !=
                 -1) {
            buffer[strcspn(buffer, "\n")] = 0;
            patterns = realloc(patterns, (pattern_count + 1) * sizeof(char *));
            patterns[pattern_count] = strdup(buffer);
            pattern_count++;
          }

          free(buffer);
          fclose(file_pattern);

          int count_arg_no_flag = argc - flag_count - 2;

          grep(file, search_word, count_arg_no_flag, file_name, options.pattern,
               options.ignor_up_lower_case, options.invert_match,
               options.output_count, options.output_matching,
               options.number_line, options.matching_lines_without_files,
               options.take_regexes, options.matched_parts, patterns,
               pattern_count);

          for (int i = 0; i < pattern_count; i++) {
            free(patterns[i]);
          }
          free(patterns);
          fclose(file);
        }
      }
    }
  }

  return 0;
}
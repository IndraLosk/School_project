#include "s21_cat.h"

void init_opt(opt *options) {
  options->number_nonblank = false;
  options->show_ends = false;
  options->number_all = false;
  options->squeeze_blank = false;
  options->show_tabs = false;
  options->show_nonprintable = false;
  options->is_opt = true;
}

void cat(FILE *file_name, bool number_nonblank, bool show_ends, bool number_all,
         bool squeeze_blank, bool show_tabs, bool show_nonprintable) {
  int c;
  int count_empty = 1;
  int count_all = 1;
  int long_str = 0;
  bool last_was_newline = false;
  bool new_line = true;

  while ((c = fgetc(file_name)) != EOF) {
    if (c == '\n') {
      if (number_all && !number_nonblank) {
        if (new_line && !squeeze_blank) {
          printf("%6d\t", count_all);
          count_all++;
        }
        if (squeeze_blank && !last_was_newline && new_line) {
          printf("%6d\t", count_all);
          count_all++;
        }
      }
      if (show_ends) {
        if (number_nonblank && long_str == 0) {
          if (squeeze_blank && !last_was_newline)
            printf("\t$");
          else if (!squeeze_blank)
            printf("\t$");
        } else if (squeeze_blank && !last_was_newline) {
          printf("$");
        } else if (!squeeze_blank) {
          printf("$");
        }
      }

      if (squeeze_blank && long_str == 0) {
        if (!last_was_newline) {
          printf("\n");
          last_was_newline = true;
        }
      } else {
        printf("\n");
        last_was_newline = false;
      }

      long_str = 0;
      new_line = true;

    } else {
      if (number_all && new_line && !number_nonblank) {
        printf("%6d\t", count_all);
        count_all++;
        new_line = false;
      }
      if (number_nonblank && long_str == 0) {
        printf("%6d\t", count_empty);
        count_empty++;
      }
      if (show_tabs && c == '\t')
        printf("^I");
      else if (show_nonprintable) {
        if (c >= 128 && c <= 159) {
          printf("M-^%c", c - 64);
        } else if (c <= 31 && c != 9 && c != 10) {
          printf("^%c", c + 64);
        } else if (c == 127) {
          printf("^?");
        } else {
          printf("%c", c);
        }
      } else {
        putchar(c);
      }
      long_str++;
      last_was_newline = false;
    }
  }
}

int main(int argc, char *argv[]) {
  opt options;
  init_opt(&options);

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        if (strcmp(argv[i], "--number-nonblank") == 0) {
          options.number_nonblank = true;
        } else if (strcmp(argv[i], "--number") == 0) {
          options.number_all = true;
        } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
          options.squeeze_blank = true;
        } else {
          printf(
              "usage: cat [--number-nonblank] [--number] [--squeeze-blank] "
              "[file ...]\n");
          options.is_opt = false;
          break;
        }
      } else {
        for (int j = 1; argv[i][j] != '\0'; j++) {
          switch (argv[i][j]) {
            case 'b':
              options.number_nonblank = true;
              break;
            case 'e':
              options.show_nonprintable = true;
              options.show_ends = true;
              break;
            case 'E':
              options.show_ends = true;
              break;
            case 'n':
              options.number_all = true;
              break;
            case 's':
              options.squeeze_blank = true;
              break;
            case 't':
              options.show_nonprintable = true;
              options.show_tabs = true;
              break;
            case 'T':
              options.show_tabs = true;
              break;
            case 'v':
              options.show_nonprintable = true;
              break;
            default:
              printf("usage: cat [-benst] [file ...]\n");
              options.is_opt = false;
              break;
          }
          if (!options.is_opt) {
            break;
          }
        }
      }
    } else {
      FILE *file = fopen(argv[i], "r");
      if (file == NULL) {
        printf("No such file or directory");
        break;
      } else if (options.is_opt) {
        cat(file, options.number_nonblank, options.show_ends,
            options.number_all, options.squeeze_blank, options.show_tabs,
            options.show_nonprintable);
        fclose(file);
      }
    }
  }

  return 0;
}
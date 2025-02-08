#include <ctype.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  bool pattern;                       // -e
  bool ignor_up_lower_case;           // -i
  bool invert_match;                  // -v
  bool output_count;                  // -c
  bool output_matching;               // -l
  bool number_line;                   // -n
  bool matching_lines_without_files;  // -h
  bool suppress_error_messages;       // -s
  bool take_regexes;                  // -f
  bool matched_parts;                 // -o

} opt;

void init_opt(opt *options);
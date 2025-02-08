#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

typedef struct {
  bool number_nonblank;  // нумерует только непустые строки
  bool show_ends;  // также отображает символы конца строки как $
  bool number_all;  // нумерует все выходные строки
  bool squeeze_blank;  // сжимает несколько смежных пустых строк
  bool show_tabs;          // также отображает табы как ^I
  bool show_nonprintable;  // -v
  bool is_opt;
} opt;

void init_opt(opt *options);
void cat(FILE *file_name, bool number_nonblank, bool show_ends, bool number_all,
         bool squeeze_blank, bool show_tabs, bool show_nonprintable);

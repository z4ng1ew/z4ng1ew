#include "s21_cat.h"

int main(int countArg, char **arrPoint) {
  flags option = {0};  
  int exit_status = 0;
  int number_file =
      get_opt(countArg, arrPoint, &option);  

  if (option.err_f == 1) {
    printf("Пожалуйста, используйте следующие опции: beEvnstT\n");
    exit_status = 1;
  } else {
    while (number_file < countArg) {
      char *path = arrPoint[number_file];
      cat(path,
          option);  
      number_file++;
    }
  }

  return exit_status;
}

int get_opt(int countArg, char **arrPoint, flags *flag) {
  int c = 0;
  int option_index = 0;
  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {0, 0, 0, 0}};

  while ((c = getopt_long(countArg, arrPoint, "beEvnstT", long_options,
                          &option_index)) != -1) {
    handle_option(c, flag);
  }
  if (flag->b) flag->n = 0;
  return optind;
}

void handle_option(int c, flags *flag) {
  if (c == 'b') {
    flag->b = 1;
  } else if (c == 'e') {
    flag->E = 1;
    flag->v = 1;
  } else if (c == 'E') {
    flag->E = 1;
  } else if (c == 'v') {
    flag->v = 1;
  } else if (c == 'n') {
    flag->n = 1;
  } else if (c == 's') {
    flag->s = 1;
  } else if (c == 't') {
    flag->T = 1;
    flag->v = 1;
  } else if (c == 'T') {
    flag->T = 1;
  } else {
    flag->err_f = 1;
  }
}

void process_file(FILE *filename, flags flag) {
  int ch, prev = '\n', current_line = 1, str = 0;
  while ((ch = getc(filename)) != EOF) {
    if (s(flag, &prev, &ch, &str)) continue;
    b(flag, &prev, &ch, &current_line);
    n(flag, &prev, &current_line);
    E(flag, &prev, &ch);
    T(flag, &ch);
    v(flag,
      &ch);  
    if (ch != 0) {  
      putchar(ch);
    }
    prev = ch;
  }
}

void cat(char *path, flags flag) {
  FILE *filename = fopen(path, "r");
  if (!filename) {
    fprintf(stderr, "No such file or directory\n");
    return;
  }
  process_file(filename, flag);
  fclose(filename);
}

int s(flags flag, int *prev, int *ch, int *str) {
  int f = 0;
  if (flag.s == 1 && (*prev == '\n' && *ch == '\n')) {
    *str += 1;
    if (*str > 1) {
      f = 1;
    }
  } else {
    *str = 0;
  }
  return f;
}

void b(flags flag, int *prev, int *ch, int *current_line) {
  if (flag.b == 1) {
    if (*prev == '\n' && *ch != '\n') {
      printf("%*d\t", 6, *current_line);
      *current_line += 1;
    }
  }
}

void n(flags flag, int *prev, int *current_line) {
  if (flag.n == 1) {
    if (*prev == '\n') {
      printf("%*d\t", 6, *current_line);
      *current_line += 1;
    }
  }
}

void E(flags flag, int *prev, int *ch) {
  if (flag.E == 1) {
    if (*prev != '\0' && *ch == '\n') {
      if (*prev == '\n' && flag.b) {
        printf("      \t$");
      } else {
        int dollar = '$';
        putc(dollar, stdout);
      }
    }
  }
}

void T(flags flag, int *ch) {
  if (flag.T == 1) {
    if (*ch == '\t') {
      printf("^");
      *ch = 'I';
    }
  }
}

void v(flags flag, int *ch) {
  if (flag.v == 1) {
    if (*ch >= 0 && *ch < 32 && *ch != '\n' && *ch != '\t') {
      printf("^%c", *ch + 64);
      *ch = 0;
    } else if (*ch == 127) {
      printf("^?");
      *ch = 0;
    } else if (*ch > 127 && *ch < 160) {
      printf("M-^%c", *ch - 128 + 64);
      *ch = 0;
    } else if (*ch >= 160 && *ch < 255) {
      printf("M-%c", *ch - 128);
      *ch = 0;
    } else if (*ch == 255) {
      printf("M-^?");
      *ch = 0;
    }
  }
}


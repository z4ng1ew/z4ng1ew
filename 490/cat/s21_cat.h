#ifndef s21_cat
#define s21_cat

#include <getopt.h>
#include <stdio.h>

typedef struct {
  int b;
  int e;
  int E;
  int v;
  int n;
  int s;
  int t;
  int T;
  int d;
  int err_f;
} flags;

int get_opt(int argc, char **argv, flags *flag);
void cat(char *path, flags flag);
void handle_option(int c, flags *flag);

int s(flags flag, int *prev, int *ch, int *str);
void b(flags flag, int *prev, int *ch, int *current_line);
void n(flags flag, int *prev, int *current_line);
void E(flags flag, int *prev, int *ch);
void T(flags flag, int *ch);
void v(flags flag, int *ch);

void process_file(FILE *filename, flags flag);

#endif

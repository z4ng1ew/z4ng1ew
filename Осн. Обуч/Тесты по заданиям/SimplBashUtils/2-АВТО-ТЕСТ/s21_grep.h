#ifndef s21_grep
#define s21_grep

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 10000

typedef struct {
  int eflag;
  int iflag;
  int vflag;
  int cflag;
  int lflag;
  int nflag;
  int hflag;
  int sflag;
  int oflag;
  int fflag;
  int lflag_file_match;
  int nflag_count_str;
  char arg_namefile[BUFFER];
  char o_namefile[BUFFER];
  char arg_fflag[BUFFER];
  char str_file[BUFFER];
  char str_arguments[BUFFER];
  char str_arguments_2[BUFFER];
} flags;

void get_opt(int argc, char *argv[], flags *options);
void handle_flag(int opt, flags *options);
void grep(int counter_files, char *argv[], flags *options);
void process_file(FILE *file, int counter_files, char *argv[], regex_t *reg,
                  regmatch_t *first, int *counter_str, flags *options);
void fflag(flags *options);
void sym_eof(flags *options);
void oflag(int match, regex_t reg, regmatch_t first, int counter_files,
           char *argv[], flags *options);

#endif

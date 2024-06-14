#include "s21_grep.h"

int main(int argc, char *argv[]) {
  flags options = {0};
  int error_flag = 0;

  if (argc == 1) {
    printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
    printf("Try 'grep --help' for more information.\n");
    error_flag = 1;  // Устанавливаем флаг ошибки
  } else {
    get_opt(argc, argv, &options);
    int counter_files = argc - optind;
    while (optind < argc) {
      grep(counter_files, argv, &options);
      optind++;
    }
  }
  return error_flag;
}

void get_opt(int argc, char *argv[], flags *options) {
  int opt = 0;

  while ((opt = getopt_long(argc, argv, "e:ivclnhsof:", NULL, 0)) != -1) {
    handle_flag(opt, options);
  }
  if (!options->eflag && !options->fflag) {
    if (argc > optind) {
      strcat(options->str_arguments, argv[optind]);
    }
    optind++;
  }
  if (options->eflag || options->fflag) {
    options->str_arguments[strlen(options->str_arguments) - 1] = '\0';
  }
}

void handle_flag(int opt, flags *options) {
  if (opt == 'e') {
    options->eflag = 1;
    strcat(options->str_arguments, optarg);
    strcat(options->str_arguments, "|");
  } else if (opt == 'i') {
    options->iflag = 1;
  } else if (opt == 'v') {
    options->vflag = 1;
  } else if (opt == 'c') {
    options->cflag = 1;
  } else if (opt == 'l') {
    options->lflag = 1;
  } else if (opt == 'n') {
    options->nflag = 1;
  } else if (opt == 'h') {
    options->hflag = 1;
  } else if (opt == 's') {
    options->sflag = 1;
  } else if (opt == 'o') {
    options->oflag = 1;
  } else if (opt == 'f') {
    options->fflag = 1;
    strcpy(options->arg_namefile, optarg);
    fflag(options);
  } else {
    printf("Неправильный флаг\n");
  }
}

void grep(int counter_files, char *argv[], flags *options) {
  FILE *file;
  regex_t reg;
  regmatch_t first;
  int counter_str = 0;
  int flags_regular = REG_EXTENDED;
  if (options->iflag) {
    flags_regular = REG_EXTENDED | REG_ICASE;
  }
  const char *pattern =
      options->fflag ? options->str_arguments_2 : options->str_arguments;
  regcomp(&reg, pattern, flags_regular);

  file = fopen(argv[optind], "r");
  if (file != NULL) {
    process_file(file, counter_files, argv, &reg, &first, &counter_str,
                 options);
    fclose(file);
  } else if (!options->sflag) {
    fprintf(stderr, "No such file or directory\n");
  }
  regfree(&reg);
}

void process_file(FILE *file, int counter_files, char *argv[], regex_t *reg,
                  regmatch_t *first, int *counter_str, flags *options) {
  while ((fgets(options->str_file, BUFFER, file)) != NULL) {
    int match = regexec(reg, options->str_file, 1, first, 0);
    options->nflag_count_str++;
    if (options->vflag) match = !match;
    if (!match && options->str_file[0] != '\n') (*counter_str)++;
    if (!match && options->lflag) options->lflag_file_match = 1;
    if (!match && options->nflag) {
      if (counter_files == 1)
        printf("%d:%s", options->nflag_count_str, options->str_file);
      if (counter_files > 1)
        printf("%s:%d:%s", argv[optind], options->nflag_count_str,
               options->str_file);
      if (counter_files > 0) sym_eof(options);
    }
    if (options->oflag == 1)
      oflag(match, *reg, *first, counter_files, argv, options);
    if (!match && !options->cflag && !options->lflag && !options->nflag &&
        !options->oflag) {
      if (counter_files == 1 || options->hflag) printf("%s", options->str_file);
      if (counter_files > 1 && !options->hflag)
        printf("%s:%s", argv[optind], options->str_file);
      if (*counter_str > 0) sym_eof(options);
    }
  }
  if (options->cflag == 1) {
    if (counter_files == 1) printf("%d\n", *counter_str);
    if (counter_files > 1) printf("%s:%d\n", argv[optind], *counter_str);
  }
  if (options->lflag == 1 && options->lflag_file_match == 1)
    printf("%s\n", argv[optind]);
  options->nflag_count_str = 0;
}

void fflag(flags *options) {
  FILE *file2;
  file2 = fopen(options->arg_namefile, "rb");
  if (file2 != NULL) {
    while (fgets(options->arg_fflag, BUFFER, file2) != NULL) {
      strcat(options->str_arguments_2, options->arg_fflag);
      if (options->str_arguments_2[strlen(options->str_arguments_2) - 1] != '|')
        strcat(options->str_arguments_2, "|");
    }
    options->str_arguments_2[strlen(options->str_arguments_2) - 1] = '\0';
    fclose(file2);
  }
}

void oflag(int match, regex_t reg, regmatch_t first, int counter_files,
           char *argv[], flags *options) {
  if (!match) {
    if (counter_files == 1)
      printf("%.*s\n", (int)(first.rm_eo - first.rm_so),
             options->str_file + first.rm_so);
    if (counter_files > 1)
      printf("%s:%.*s\n", argv[optind], (int)(first.rm_eo - first.rm_so),
             options->str_file + first.rm_so);
    char *remaining = options->str_file + first.rm_eo;
    while (!(regexec(&reg, remaining, 1, &first, 0))) {
      if (counter_files == 1)
        printf("%.*s\n", (int)(first.rm_eo - first.rm_so),
               remaining + first.rm_so);
      if (counter_files > 1)
        printf("%s:%.*s\n", argv[optind], (int)(first.rm_eo - first.rm_so),
               remaining + first.rm_so);
      remaining = remaining + first.rm_eo;
    }
  }
}

void sym_eof(flags *options) {
  if (options->str_file[strlen(options->str_file) - 1] != '\n' &&
      *options->str_file != '\n' && !options->fflag) {
    printf("%c", '\n');
    *options->str_file = '\n';
  }
}


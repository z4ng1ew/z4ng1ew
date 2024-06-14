#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct options_s {
    int n;
    int b;
    int v;
    int e;
    int s;
    int t;
    int error;
} opt_t;

void parser(int, char**, opt_t*);
void print(FILE*, const opt_t*);

int main(int argc, char** argv) {
    opt_t options = {0};
    parser(argc, argv, &options);
    if(!options.error) {
        for (int i = 1; i < argc; ++i) {
            if (argv[i][0] == '-') continue;
            FILE* fp;
            fp = fopen(argv[i], "r");
            print(fp, &options);
            fclose(fp);
        }
    }
    return 0;
}

void parser(int argc, char** argv, opt_t* options) {
    int option_index = 0;
    char* short_options = "nbvestTE";
    static struct option long_options[] = {
        {"number-nonblank", 0, 0, 'b'},
        {"number", 0, 0, 'n'},
        {"squeeze-blank", 0, 0, 's'}
    };
    char c;
    while((c = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (c)
        {
        case 'e':
           options->v = 1; 
        case 'E':
            options->e = 1;
            break;
        case 't':
           options->v = 1; 
        case 'T':
            options->t = 1;
            break;
        case 's':
            options->s = 1;
            break;
        case 'b':
             options->n = 0;
             options->b = 1;
             break;
        case 'n':
             options->n = !options->b;
             break;
        case 'v':
             options->v = 1;
             break;
        default:
            options->error = 1;
            break;
        }
    }

}


int isempty(char* line) {
    return line[0] == '\0' || line[0] == '\n';
}


void printLine(unsigned char* line, unsigned len, const opt_t* options) {
    for (int i = 0; i < len; ++i) {
        if (options->e && line[i] == '\n') printf("$");
        if (options->t && line[i] == '\t') {
            printf("^I");
        } else if (options->v && !isprint(line[i]) && line[i] != '\n') {
            if (line[i] == 127) printf("^?");
            else if (iscntrl(line[i])) {
                printf("%c", line[i] + 64);
            } else if (line[i] == 255) {
                printf("M-^?");
            } else if (line[i] > 127 && line[i] < 160) {
                printf("M-^%c", line[i] - 64);
            } else if (line[i] >= 160) {
                printf("M-%c", line[i] - 128);
            } else {
                printf("%c", line[i]);
            }
        } else {
            printf("%c", line[i]);
        }
    }
}

int readLine(unsigned char** line, unsigned* len, FILE* fp) {
    unsigned int size = 0, capacity = 2;
    unsigned char c;

    if (line != NULL) free(line);
    line = malloc(sizeof(unsigned char*) * capacity);

    while ((c = fgetc(fp) != '\n' && !feof(fp) && !ferror(fp))) {
        if (size + 2 == capacity) {
            capacity *= 2;
            line = realloc(line, capacity);
        }
        line[size++] = c;
    }
    if (c == '\n') line[size++] = '\n';

    if (feof(fp) || ferror(fp)) return -1;
    return 0;
}


void print(FILE* fp, const opt_t* options) {
     unsigned int len, line_num = 1;
     unsigned char* line;
     int skipline = 0;
     while (readLine(&line, &len, fp) != -1) {
        if (options->s &&line isempty(line) && skipline) {
            continue;
        }
        if (isempty(line)) skipline = 1;
        else skipline = 0;

        if (options->n || (options->b && !isempty(line))) {
            printf("%6d", line_num++);
        }
        len = strlen(line);
        printLine(line, len, options);

     }
     free(line);
}
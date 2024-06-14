#include "grep.h"
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
    opt_t options = {false};
    templates_t templates;
    templates.size = 0;
    templates.capacity = 2;
    templates.data = malloc(sizeof(char *) * templates.capacity);
    parseArgs(argc, argv, &options, &templates);
    if (!options.is_error) {
        int flag = getFlag(&options);
        readFiles(argc, argv, &options, &templates, flag);
    }
    for (unsigned i = 0; i < templates.size; ++i) {
        free(templates.data[i]);
    }
    free(templates.data);
    return 0;
}


int isMaxInterval(regmatch_t* matches, int start, int size, regmatch_t match) {
    for (int i = start; i < size; ++i) {
        if (match.rm_so == matches[i].rm_so && match.rm_eo < matches[i].rm_eo) {
            return 0;
        }
    }
    return 1;
}


int isUnique(regmatch_t* matches, int size, regmatch_t match) {
    for (int i = 0; i < size; ++i) {
        if (matches[i].rm_so == match.rm_so) {
            return 0;
        }
    }
    return 1;
}


int filter_matches(regmatch_t* matches, int size) {
    regmatch_t* filtered_matches = malloc(sizeof(regmatch_t) * size);
    int k = 0;
    for (int i = 0; i < size; ++i) {
        if (isMaxInterval(matches, i, size, matches[i]) && isUnique(filtered_matches, k, matches[i])) {
            filtered_matches[k] = matches[i];
            ++k;
        }
    }
    free(matches);
    matches = filtered_matches;
    return k;
}


void print(FILE* fp, char* filename, const opt_t* options, const templates_t* templates, int flag, int files_count) {

    unsigned long len = 0, line_num = 1, count = 0;
    char* line = NULL;
    while (getline(&line, &len, fp) != - 1) {
        unsigned int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
        }
        count += processLine(line, filename, options, templates, flag, line_num);
        ++line_num;
    }
    if (options->l && count > 0) {
        printf("%s:", filename);
    } else if (options->c && count > 0) {
        if (!options->h && files_count > 0) {
            printf("%s:", filename);
        }
        printf("%lu", count);
    }
}

int processLine(char* line, char* filename, const opt_t* options, 
                const templates_t* templates, int flag, int line_num) {
    bool matched = false;
    int matches_capacity = 2;
    regmatch_t* matches = (regmatch_t*)malloc(sizeof(regmatch_t) * matches_capacity);
    int num_matches = 0;
    regex_t reg;

    for (unsigned int i = 0; i < templates->size; ++i) {

        if (matched && !options->o) {
            break;
        }

        int offset = 0;
        regcomp(&reg, templates->data[i], flag);
        regmatch_t match;
        while (regexec(&reg, line + offset, 1, &match, flag) == 0) {
            matched = true;

            if (options->l || options->c) {
                break;
            }
            
            if (options->o) {
                if (num_matches + 1 == matches_capacity) {
                    matches_capacity *= 2;
                    matches = realloc(matches, matches_capacity);
                }
                match.rm_so += offset;
                match.rm_eo += offset;
                matches[num_matches++] = match;
                offset = match.rm_eo;

            } else {
                if (!options->h) {
                printf("%s:", filename);
                }
                if (options->n) {
                    printf("%d:", line_num);
                }
                printf("%s\n", line);
                break;
            }
        }

    }
    regfree(&reg);

    if (options->o && num_matches > 0) {
        num_matches = filter_matches(matches, num_matches);
        for (int i = 0; i < num_matches; ++i) {
            for (int j = matches[i].rm_so; j < matches[i].rm_eo; ++j) {
                printf("%c", line[j]);
            }
            printf("\n");
        }
    }
    free(matches);

    return matched;
}


int getFlag(const opt_t* opt) {
    int flag = 0;
    if (opt->e) {
        flag |= REG_EXTENDED;
    }
    if (opt->i) {
        flag |= REG_ICASE;
    }
    return flag;

}

void checkCapacity(templates_t* templates) {
    if ((templates->size + 1 == templates->capacity)) {
        templates->capacity *= 2;
        char**tmp = malloc(sizeof(char *) * templates->capacity);
        for (unsigned i = 0; i < templates->size; ++i) {
            tmp[i] = templates->data[i];
        }
        free(templates->data);
        templates->data = tmp;
    }
}

void parseArgs(int argc, char** argv, opt_t* options, templates_t* templates) {
    char* short_options = "e:ivclnhsf:o";    
    int op;

    while((op = getopt(argc, argv, short_options)) != -1) {
        switch (op) {
            case 'e': 
                options->e = true;
                parseTemplates(templates);
                break;
            case 'i':
                options->i = true;
                break;
            case 'v': 
                options->v = true;
                break;
            case 'c': 
                options->c = true;
                break;
            case 'l': 
                options->l = true; 
                break;
            case 'n': 
                options->n = true;
                break;
            case 'h': 
                options->h = true;
                break;
            case 's': 
                options->s = true;
                break;
            case 'f': 
                options->f = true;
                parseTemplatesfromFile(templates, options);
                break;
            case 'o': 
                options->o = true;
                break;
            default:
                options->is_error = true;
                return ;
        }
    }
}


void readFiles(int argc, char** argv, const opt_t* options, templates_t* templates, int flag) {
    if (!options->e && !options->f) {
        int len = strlen(argv[optind]);
        templates->data[templates->size] = malloc(sizeof(char) * len);
        strcpy(templates->data[templates->size++], argv[optind++]);
    }

    for (int i = optind; i < argc; ++i) {
        FILE* fp = fopen(argv[i], "r");
        if (fp == NULL) {
            if (!options->s) {
                fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
            }
            continue;
        }
        print(fp, argv[i], options, templates, flag, argc - optind - 1); 
        fclose(fp);
    }
}

void parseTemplates(templates_t* templates) {
    checkCapacity(templates);
    int len = strlen(optarg);
    templates->data[templates->size] = malloc(sizeof(char) * len);
    strcpy(templates->data[templates->size], optarg);
    templates->size++;
}

void parseTemplatesfromFile(templates_t* templates, opt_t* options) {
    FILE* fp = fopen(optarg, "r");
    if (fp == NULL) {
        fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
        options->is_error = true;
        return;
    }
    unsigned long len;
    char* line;
    while (getline(&line, &len, fp) != -1) {
        checkCapacity(templates);
        int len = strlen(line);
        templates->data[templates->size] = malloc(sizeof(char) * len);
        strcpy(templates->data[templates->size], line);
        if (templates->data[templates->size][len - 1] == '\n') {
            templates->data[templates->size][len - 1] = '\0';
        }
        templates->size++;
    } 
}
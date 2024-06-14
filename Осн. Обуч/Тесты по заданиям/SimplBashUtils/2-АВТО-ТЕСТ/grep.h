#include <stdbool.h>
#include <stdio.h>
#include <regex.h>

#ifndef GREP_H

typedef struct options_s {
    bool e;
    bool i;
    bool v;
    bool c;
    bool l;
    bool n;
    bool h;
    bool s;
    bool f;
    bool o;
    bool is_error;
} opt_t;


typedef struct templates {
    char ** data;
    unsigned int size;
    unsigned int capacity; 
} templates_t;

void checkCapacity(templates_t*);
void parseArgs(int, char**, opt_t*, templates_t*);
void readFiles(int, char**, const opt_t*, templates_t*, int);
void print(FILE*, char *, const opt_t*, const templates_t*, int, int);
int processLine(char*, char*, const opt_t*, const templates_t*, int, int);
int getFlag(const opt_t*);
void parseTemplates(templates_t*);
void parseTemplatesfromFile(templates_t*, opt_t*);

#endif
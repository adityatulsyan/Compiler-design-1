#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer_structs.h"
#define MAXLINELEN 2048
#define MAXTOKLEN 50

void tokenizeSourceCode(char *filename, TokenStream *s) {
    char *sep = " ";
    FILE *file = fopen(filename, "r");
    int line_num = 0;

    if (!file) {
        printf("File error!");
        return;
    }

    char line[MAXLINELEN];
    while (fgets(line, MAXLINELEN, file)) {
        line_num++;
        char *tmp_line = strdup(line); // strtok destroys a string
        tmp_line = replace_char(tmp_line, '\n', '\0');
        tmp_line = replace_char(tmp_line, '\r', '\0');

        //printf("%d: ", line_num);
        char *tok = strtok(tmp_line, sep); // read first token from the line
        while (tok) {
            // /printf("%s|", tok);
            insertIntoStream(s, line_num, tok);
            tok = strtok(NULL, sep); // read next token
        } //printf("\n");
    }
}
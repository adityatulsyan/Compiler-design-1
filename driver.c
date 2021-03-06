/*
Group 36
2017B4A70495P Manan Soni
2017B4A70549P Siddharth Singh
2017B4A70636P Nayan Khanna
2017B4A70740P Aditya Tulsyan
*/

#include <stdlib.h>
#include "gen_utils.h"
#include "grammar.h"
#include "tokenizer_structs.h"
#include "parse_tree.h"
#include "print.h"
#include "type_exp_table.h"

#define MAXLINELEN 2048
#define MAXRULES 100
//#define DEBUG /* for debug mode */

int main(int argc, char** argv){

    if (argc < 2) {
        printf("Usage: ./driver.exe <filename>\n");
        exit(1);
    }

    printf("Reading grammar from machine_grammar.txt ...\n");
    Grammar* g = (Grammar*)malloc(sizeof(Grammar));
    g->num_rules = 0;
    g->start_symb = toSymbol("main_program");
    g->rules = (Rule*)malloc(MAXRULES*sizeof(Rule));
    int gflag = readGrammar("machine_grammar.txt", g);
    #ifdef DEBUG
        printGrammar(g);
    #endif
    if (!gflag) exit(1);
    else printf("parsed grammar successfully\n\n");

    printf("Tokenizing %s ...\n", argv[1]);
    TokenStream *s = newTokenStream();
    int  tflag = tokenizeSourceCode(argv[1], s);
    #ifdef DEBUG
        for(Token *temp = s->head; temp; temp=temp->next) {
            printSymbol(temp->lexeme);
        }
    #endif
    if (!tflag) exit(1);
    else printf("tokenized successfully\n\n");

    int option, line=0;
    Parse_tree_node * p;

    do {

        printf("\n\nMenu: \n");
        printf("--------------------------------------------------------\n");
        printf("0 - Exit\n");
        printf("1 - print parse tree (without types syntax only)\n");
        printf("2 - Traverse parse tree, create Type expression table, display type errors\n");
        printf("3 - print parse tree (with types computed)\n");
        printf("4 - print type expression table\n");
        printf("--------------------------------------------------------\n");

        printf("> ");
        scanf("%d",&option);

        switch(option){
            case 0:
                freeTokenStream(s);
                //              freeGrammar(g);
                break;
            case 1:
            {
                printf("Creating parse tree ...\n");
                line = 0;
                p = createParseTree(s,g,&line);
                if (!p) {
                    printf("Syntax error while reading %s\nSuccessfully read till line: %d\n", argv[1], line);
                    exit(1);
                }
                else printf("parse tree created successfully\n\n");
                printParseTree(p,0);
                free_parse_tree(p);
                break;
            }
            case 2:
            {
                type_exp_table *t = create_type_expression_table();
                printf("Creating parse tree ...\n");
                line = 0;
                p = createParseTree(s,g,&line);
                if (!p) {
                    printf("Syntax error while reading %s\nSuccessfully read till line: %d\n", argv[1], line);
                    exit(1);
                }
                else printf("parse tree created successfully\n\n");
                init_errors();
                traverse_and_populate(t, p);
                print_all_errors();
                free_parse_tree(p);
                free_type_expression_table(t);
                break;
            }
            case 3:
            {
                printf("Creating parse tree ...\n");
                line = 0;
                p = createParseTree(s,g,&line);
                if (!p) {
                    printf("Syntax error while reading %s\nSuccessfully read till line: %d\n", argv[1], line);
                    exit(1);
                }
                else printf("parse tree created successfully\n\n");
                type_exp_table *t = create_type_expression_table();
                init_errors();
                traverse_and_populate(t, p);
                printParseTree(p,0);
                printf("\n");
                free_parse_tree(p);
                free_type_expression_table(t);
                break;
            }
            case 4:
            {
                type_exp_table *t = create_type_expression_table();
                printf("Creating parse tree ...\n");
                line = 0;
                p = createParseTree(s, g, &line);
                if (!p)
                {
                    printf("Syntax error while reading %s\nSuccessfully read till line: %d\n", argv[1], line);
                    exit(1);
                }
                else
                    printf("parse tree created successfully\n\n");

                init_errors();
                traverse_and_populate(t, p);
                print_all_errors();
                printf("Populated Type expression table successfully\n");
                print_type_exp_table(t);
                free_parse_tree(p);
                free_type_expression_table(t);
                /* printParseTree(p, 0); */
                break;
            }
            default:
                printf("invalid input\n");
                break;
        }

    } while(option != 0);
}

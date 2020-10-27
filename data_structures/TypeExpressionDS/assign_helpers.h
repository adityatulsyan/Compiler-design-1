#ifndef ASSIGN_HELPERS_H
#define ASSIGN_HELPERS_H

#include "type_exp_table.h"
#include "type_expression.h"
#include "../../final_code/parse_tree.h"

//Return type expression for fact non-terminal
type_expression *get_type_of_fact(type_exp_table *txp_table, Parse_tree_node *p);

//Return type expression for arithm-expr non-terminal
type_expression *get_type_of_arithm_expr(type_exp_table *txp_table, Parse_tree_node *p);

//Return type expression for term non-terminal
type_expression *get_type_of_term(type_exp_table *txp_table, Parse_tree_node *p);

//Checks dimensions for two rectangular arrays
bool check_rect_dimensions(rect_array_type r1, rect_array_type r2, Parse_tree_node *p,
                           char *t1, char *t2, char *operator, char *lexeme1, char *lexeme2);

//Checks dimensions for two jagged arrays
bool check_jagged_dimensions(jagged_array_type j1, jagged_array_type j2, Parse_tree_node *p,
                            char *t1, char *t2, char *operator, char *lexeme1, char *lexeme2);
#endif
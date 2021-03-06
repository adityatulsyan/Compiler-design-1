/*
Group 36
2017B4A70495P Manan Soni
2017B4A70549P Siddharth Singh
2017B4A70636P Nayan Khanna
2017B4A70740P Aditya Tulsyan
*/

#ifndef TYPE_EXP_TABLE_H
#define TYPE_EXP_TABLE_H

#include <stdlib.h>
#include "gen_utils.h"
#include "type_expression.h"

#define DEFAULT_TXP_TABLE_SIZE 60

typedef struct ____TYPE_EXPRESSION_TABLE_NODE____ txp_table_node;

typedef enum {NOT_APPLICABLE, STATIC, DYNAMIC} DeclarationType;

struct ____TYPE_EXPRESSION_TABLE_NODE____{
    char* variable_name;
    VariableType variable_type;
    DeclarationType declaration_type;
};

typedef struct ____TYPE_EXPRESSION_TABLE____ type_exp_table;

struct ____TYPE_EXPRESSION_TABLE____{
    linked_list* root; // should be a linked_list of txp_table_node(s)? But does it need to be ordered?
    hash_map* symbol_table;
};

/* Function Prototypes */
void free_type_expression_table(type_exp_table* txp_table);

void traverse_and_populate(type_exp_table* txp_table, Parse_tree_node *p);

// initialise the type expression table
type_exp_table* create_type_expression_table();

// get type expression of a variable
type_expression* get_type_expression(type_exp_table* txp_table, char* variable);

// add entry to symbol table
void add_to_symbol_table(hash_map* symbol_table, char* variable_name, type_expression* txp);

// add entry to type expression table
void add_entry_to_table(type_exp_table *txp_table, char *variable_name, VariableType var_type,
                        DeclarationType decl_type, type_expression* t);


type_expression* type_check_decl_stmt(type_exp_table* txp_table,Parse_tree_node* p);

type_expression* type_check_assign_stmt(type_exp_table* txp_table, Parse_tree_node* p);

bool are_types_equal(type_expression *t1, type_expression *t2, type_exp_table *txp_table,
                     Parse_tree_node *p);

linked_list *get_type_of_index_list(type_exp_table *txp_table, Parse_tree_node *p);

bool rect_decl_checks(type_exp_table* t, Parse_tree_node* p, DeclarationType* decl_type);

bool jagged_decl_checks(type_exp_table* txp_table, Parse_tree_node* p);

bool do_bound_checking(type_exp_table* txp_table, Parse_tree_node* p, linked_list* ll);
type_expression* get_type_of_var(type_exp_table* txp_table, Parse_tree_node* p);

#endif

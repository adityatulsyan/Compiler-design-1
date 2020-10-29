#include "jagged_array_type.h"

jagged_2d* create_jagged_2d(){
    jagged_2d *j2d = (jagged_2d*)calloc(1, sizeof(jagged_2d));
    j2d->row_sizes = create_r2_dimension();
    return j2d;
}

jagged_3d* create_jagged_3d(){
    jagged_3d *j3d = (jagged_3d*)calloc(1, sizeof(jagged_3d));
    j3d->row_sizes = create_linked_list();
    return j3d;
}
r2_dimension create_r2_dimension(){
    r2_dimension* r2 = (r2_dimension*)calloc(1, sizeof(r2_dimension));
    r2->sizes = create_linked_list();
    return *r2;
}

void append_size(linked_list *ll, int size){
    ll_append(ll, size);
}

jagged_array_type *create_jagged_array_type(Parse_tree_node *p){
    
    jagged_array_type* jat = (jagged_array_type*)calloc(1, sizeof(jagged_array_type));
    
    Parse_tree_node* third_child = p->child->next->next;
    Parse_tree_node *lower_bound = third_child->child->child->next;
    Parse_tree_node *upper_bound = lower_bound->next->next;
    Parse_tree_node* last_child = third_child->next->next->next->next;
    int l_bound = atoi(lower_bound->tok->token_name);
    int u_bound = atoi(upper_bound->tok->token_name);
    if(third_child->tok->lexeme.s == jagged2list){
        jat->dimensions = 2;
        jat->array_type.j2d = *create_jagged_2d();
        jat->array_type.j2d.lower_bound = l_bound;
        jat->array_type.j2d.upper_bound = u_bound;

        Parse_tree_node* row_size_node = last_child->next->next->next->next->next->next;
        int row_size = atoi(row_size_node->tok->token_name);
        // Parse_tree_node *row = row_size_node->next->next->next->next;
        // for(int i=0;i<row_size;i++){
        //     int value = atoi(row->child->child->tok->token_name);
        //     append_size(jat->array_type.j2d.row_sizes.sizes, value);
        // }
        append_size(jat->array_type.j2d.row_sizes.sizes, row_size);
        Parse_tree_node *last_child_1 = row_size_node->next->next->next->next->next->next;
        if(last_child_1 && last_child_1->tok->lexeme.s==jagged2init){
            // call this again
        }
    }
    
    else{
        jat->dimensions = 3;
        jat->array_type.j3d = *create_jagged_3d();
        jat->array_type.j3d.lower_bound = l_bound;
        jat->array_type.j3d.upper_bound = u_bound;
    }


    return jat;
}
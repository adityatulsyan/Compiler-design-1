/*
Group 36
2017B4A70495P Manan Soni
2017B4A70549P Siddharth Singh
2017B4A70636P Nayan Khanna
2017B4A70740P Aditya Tulsyan
*/

#include<stdlib.h>
#include "type_exp_table.h"
#include "print.h"
// gcc *.c ../linked_list.c ../hash_map.c ../../final_code/grammar_structs.c ../../final_code/parse_tree.c ../../util/gen_utils.c -o exe

int main(){ 
    jagged_array_type* jat = (jagged_array_type*)calloc(1, sizeof(jagged_array_type));
    jat->dimensions = 2;
    jat->array_type.j2d = *create_jagged_2d();
    jat->array_type.j2d.lower_bound = 2;
    jat->array_type.j2d.upper_bound = 5;
    int a, b, c, d;
    a = 3;
    b = 4;
    c = 5;
    d = 2;
    printf("sdf\n");
    append_size(jat->array_type.j2d.row_sizes.sizes, a);
    append_size(jat->array_type.j2d.row_sizes.sizes, b);
    append_size(jat->array_type.j2d.row_sizes.sizes, c);
    append_size(jat->array_type.j2d.row_sizes.sizes, d);
    union_to_be_named *u = (union_to_be_named *)calloc(1, sizeof(union_to_be_named));
    printf("sdf\n");
    u->jagged_array_data = *jat;
    VariableType var = 2;
    printf("%d\n", *((int*)(u->jagged_array_data.array_type.j2d.row_sizes.sizes->head->next->data)));
    type_expression* tp = construct_type_expression(var, *u);
    char* str = get_string_representation(tp);
    printf("%s", str);
    return 0;

    /*     rect_array_type *r = (rect_array_type *)calloc(1, sizeof(rect_array_type)); */
    /*     r->dimensions = 2; */
    /*     r->array_ranges = create_linked_list(); */
    /*     rect_array_range *r_node = create_rect_array_node(2, 5); */
    /*     ll_append(r->array_ranges, r_node); */
    /*     rect_array_range *r_node1 = create_rect_array_node(4, 7); */
    /*     ll_append(r->array_ranges, r_node1); */
    /*     rect_array_range* rect = (rect_array_range*)r->array_ranges->head->next->data; */
    /*     printf("\ndimension of the array = %d, %d \n", r->dimensions, rect->lower_bound); */

    /*     type_exp_table *t = create_type_expression_table(); */
    /*     printf("%d %d\n",t->root->num_nodes, t->symbol_table->num_buckets); */
    /*     VariableType variable_type = RECT_ARRAY; */
    /*     union_to_be_named *u = (union_to_be_named*)calloc(1, sizeof(union_to_be_named)); */
    /*     u->rect_array_data = *r; */

    /*     rect_array_type r1 = u->rect_array_data; */
    /*     printf("RType_dimension: %d \n", r1.dimensions);  */
    /*     rect_array_range* r_temp = r1.array_ranges->head->next->data; */
    /*     printf("2nd Range LB: %d\n", r_temp->lower_bound); */

    /*     type_expression *txp = construct_type_expression(variable_type, *u); */
    /*     char buffer[100]; */
    /*     char* res=buffer; */
    /*     strcpy(res,get_string_representation(txp)); */
    /*     printf("%s\n", res); */
    /*     DeclarationType decl_type = STATIC; */
    /*     char *variable_name = "r"; */
    /*     add_entry_to_table(t, variable_name, variable_type,decl_type, txp); */
    /*     type_expression *txp2 = get_type_expression(t, variable_name); */
    /*     strcpy(res, get_string_representation(txp2)); */
    /*     printf("%s\n", res); */

    /*     t_primitive_type* primitive = (t_primitive_type*)calloc(1,sizeof(t_primitive_type)); */
    /*     variable_name = "primitive"; */
    /*     variable_type = PRIMITIVE_TYPE; */
    /*     decl_type = NOT_APPLICABLE; */
    /*     *primitive = t_INTEGER; */
    /*     union_to_be_named *u1 = (union_to_be_named *)calloc(1, sizeof(union_to_be_named)); */
    /*     u1->primitive_data = *primitive; */
    /*     txp = construct_type_expression(variable_type, *u1); */
    /*     strcpy(res, get_string_representation(txp)); */
    /*     printf("%s\n", res); */
    /*     add_entry_to_table(t, variable_name, variable_type, decl_type, txp); */
    /*     txp2 = get_type_expression(t, variable_name); */
    /*     strcpy(res, get_string_representation(txp2)); */
    /*     printf("%s\n", res); */
    /*     printf("%d\n", t->root->num_nodes); */

    /*     print_type_exp_table(t); */
}

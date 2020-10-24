#include <stdlib.h>
#include "../util/gen_utils.h"

typedef struct ____LINKED_LIST_NODE____ ll_node;

struct ____LINKED_LIST_NODE____
{
    void *data;
    ll_node *next;
    ll_node *prev;
};

typedef struct ____LINKED_LIST____ linked_list;

struct ____LINKED_LIST____
{
    ll_node *head;
    ll_node *tail;
    int num_nodes;
};

linked_list *create_linked_list();

void ll_add_at(linked_list *ll, void *data, int idx);

void ll_append(linked_list *ll, void *data);

void ll_prepend(linked_list *ll, void *data);

void *ll_remove_at(linked_list *ll, int idx);

void *ll_get(linked_list *ll, int idx);

int ll_num_nodes(linked_list *ll);
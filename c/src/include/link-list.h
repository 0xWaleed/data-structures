

#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stddef.h>
#include <stdbool.h>
#include <clist.h>

typedef struct linklist_node linklist_node_s;

struct linklist_node
{
    void* value;
    linklist_node_s* next;
};

typedef struct linklist linklist_s;

struct linklist
{
    size_t size;
    linklist_node_s* head;
    linklist_node_s* tail;
};


#ifdef __cplusplus
extern "C" {
#endif

linklist_s* linklist_create();

void linklist_add(linklist_s* linklist, void* value);

void linklist_traverse(linklist_node_s* node, clist_s* list);

linklist_node_s* linklist_find(linklist_s* linklist, bool(* predicate)(void* value));

#ifdef __cplusplus
}
#endif

#endif //LINK_LIST_H

#include <stdlib.h>
#include "include/link-list.h"

linklist_s* linklist_create()
{
    linklist_s* l = calloc(1, sizeof(linklist_s));
    return l;
}


void linklist_add(linklist_s* linklist, void* value)
{
    linklist_node_s* node = calloc(1, sizeof(linklist_node_s));
    node->value = value;
    linklist->size++;
    if (linklist->head == NULL)
    {
        linklist->head = node;
        linklist->tail = linklist->head;
        return;
    }
    linklist->tail->next = node;
    linklist->tail = node;
}

void linklist_traverse(linklist_node_s* node, clist_s* list)
{
    if (node == NULL)
    {
        return;
    }

    clist_add(list, node->value);

    if (node->next == NULL)
    {
        return;
    }

    linklist_traverse(node->next, list);
}

linklist_node_s* linklist_find(linklist_s* linklist, bool(* predicate)(void* value))
{
    linklist_node_s* node = linklist->head;

    while (node)
    {

        if (predicate(node->value))
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

void linklist_remove(linklist_s* linklist, predicate_t predicate)
{
    linklist_node_s* node = linklist->head;
    linklist_node_s* left = NULL;

    while (node)
    {
        if (predicate(node->value))
        {
            if (!left)
            {
                linklist->head = node->next;
            }
            else
            {
                left->next = node->next;
            }

            free(node);
            linklist->size--;
            break;
        }
        left = node;
        node = node->next;
    }
}

void internal_recursive_free(linklist_node_s* node)
{
    if (node == NULL)
    {
        return;
    }
    internal_recursive_free(node->next);
    free(node);
}

void linklist_destroy(linklist_s** linklist)
{
    linklist_s* l = *linklist;
    internal_recursive_free(l->head);
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    free(l);
}

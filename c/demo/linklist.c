#include <link-list.h>
#include <printf.h>
#include <string.h>

void printItems(const clist_s* list);

bool findHello(void* value)
{
    return !strcmp(value, "World");
}

bool helloPredicate(void* value)
{
    return !strcmp(value, "Hello");
}

int main()
{
    linklist_s* linklist = linklist_create();

    linklist_add(linklist, "Hello");
    linklist_add(linklist, "World");

    clist_s* list = clist_create(linklist->size);

    linklist_traverse(linklist->head, list);

    printItems(list);

    printf("found: %s\n", (char*)linklist_find(linklist, findHello)->value);

    linklist_remove(linklist, helloPredicate);

    clist_clear(list);

    linklist_traverse(linklist->head, list);

    printItems(list);

    clist_destroy(&list);
    linklist_destroy(&linklist);
    return 0;
}

void printItems(const clist_s* list)
{
    for (int i = 0; i < list->size; ++i)
    {
        printf("%s\n", (char*)list->values[i]);
    }
}


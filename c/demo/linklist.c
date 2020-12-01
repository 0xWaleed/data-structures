#include <link-list.h>
#include <printf.h>
#include <string.h>

bool findHello(void* value)
{
    return !strcmp(value, "World");
}

int main()
{
    linklist_s* linklist = linklist_create();

    linklist_add(linklist, "Hello");
    linklist_add(linklist, "World");

    clist_s* list = clist_create(linklist->size);

    linklist_traverse(linklist->head, list);

    for (int i = 0; i < list->size; ++i)
    {
        printf("%s\n", (char*)list->values[i]);
    }

    printf("found %s\n", (char*)linklist_find(linklist, findHello)->value);
    clist_destroy(&list);
    linklist_destroy(&linklist);
    return 0;
}


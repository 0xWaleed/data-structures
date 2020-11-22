

#include <stack.h>
#include <printf.h>

stack_s* m_stack;

void add_item(char* name)
{
    stack_push(m_stack, name);
}

void print_items()
{
    for (int i = 0; i < m_stack->size; ++i)
    {
        printf("%d: %s\n", i, (char*)m_stack->items[i]);
    }
}

int main()
{
    stack_options_s options;
    options.max_size = 4;
    m_stack = stack_create(&options);

    printf("is_empty: %d\n", m_stack->is_empty);
    printf("is_full: %d\n", m_stack->is_full);

    add_item("C");
    add_item("C++");
    add_item("Python");
    add_item("C#");

    print_items();

    printf("is_empty: %d\n", m_stack->is_empty);
    printf("is_full: %d\n", m_stack->is_full);


    stack_destroy(m_stack);

    return 0;
}

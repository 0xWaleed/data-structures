

#include <stack.h>
#include <printf.h>

stack_s* m_stack;

void print_items()
{

    printf("============[size(%lu)]============\n", m_stack->size);
    for (int i = 0; i < m_stack->size; ++i)
    {
        printf("%d: %s\n", i, (char*)m_stack->items[i]);
    }
    printf("+++++++++++++++++++++++++++++++++\n");
}

int main()
{
    stack_options_s options;
    options.max_size = 4;
    m_stack = stack_create(&options);

    printf("is_empty: %d\n", m_stack->is_empty);
    printf("is_full: %d\n", m_stack->is_full);

    stack_push(m_stack, "C");
    stack_push(m_stack, "C++");
    stack_push(m_stack, "Python");
    stack_push(m_stack, "C#");

    print_items();

    stack_pop(m_stack);

    print_items();

    stack_pop(m_stack);
    stack_pop(m_stack);

    print_items();

    stack_pop(m_stack);

    print_items();

    printf("is_empty: %d\n", m_stack->is_empty);
    printf("is_full: %d\n", m_stack->is_full);


    stack_destroy(m_stack);
    m_stack = NULL;

    return 0;
}

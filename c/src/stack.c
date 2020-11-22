
#include "include/stack.h"

stack_s* stack_create(stack_options_s* options)
{
    stack_s* stack = calloc(1, sizeof(stack_s));

    stack->max_size = options == NULL
                      ? STACK_DEFAULT_MAX_SIZE
                      : options->max_size;

    stack->items = malloc(sizeof(NULL) * stack->max_size);
    stack->is_empty = true;
    stack->is_full = false;
    return stack;
}


void stack_push(stack_s* stack, void* item)
{
    if (stack->size >= stack->max_size)
    {
        stack->is_full = true;
        return;
    }
    stack->items[stack->size] = item;
    stack->is_full = stack->size >= stack->max_size;
    stack->size++;
    stack->is_empty = false;
}


void* stack_pop(stack_s* stack)
{
    if (stack->size < 1)
    {
        return NULL;
    }
    --stack->size;
    stack->is_empty = stack->size < 1;
    stack->is_full = stack->size >= stack->max_size;
    return stack->items[stack->size];
}

void* stack_peek(stack_s* stack)
{
    if (stack->is_empty)
    {
        return NULL;
    }
    return stack->items[--stack->size];
}

void stack_destroy(stack_s* stack)
{
    stack->max_size = 0;
    stack->size = 0;
    stack->items = NULL;
    stack->is_empty = false;
    stack->is_full = false;
}

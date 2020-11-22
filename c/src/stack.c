
#include "include/stack.h"

stack_s* stack_create(stack_options_s* options)
{
    stack_s* stack = malloc(sizeof(stack_s));
    stack->max_size = options->max_size;
    return stack;
}

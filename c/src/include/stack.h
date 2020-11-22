

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

#define STACK_DEFAULT_MAX_SIZE 64

typedef struct stack stack_s;

struct stack
{
    size_t max_size;
    size_t size;
    void** items;
    bool is_empty;
    bool is_full;
};

typedef struct stack_options stack_options_s;

struct stack_options
{
    size_t max_size;
};


#ifdef __cplusplus
extern "C" {
#endif

stack_s* stack_create(stack_options_s* options);

void stack_push(stack_s* stack, void* item);

void* stack_pop(stack_s* stack);

void* stack_peek(stack_s* stack);

#ifdef __cplusplus
}
#endif

#endif //STACK_H

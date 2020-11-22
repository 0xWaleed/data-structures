

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack stack_s;

struct stack
{
    size_t max_size;
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


#ifdef __cplusplus
}
#endif

#endif //STACK_H

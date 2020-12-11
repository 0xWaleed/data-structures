
#include <catch2/catch.hpp>
#include <stack.h>

TEST_CASE("stack")
{
    SECTION("creating")
    {
        SECTION("creating a stack with options")
        {
            SECTION("max size should of stack_s should be same given option")
            {
                stack_options_s stack_options;
                stack_options.max_size = 1;
                stack_s* stack = stack_create(&stack_options);
                REQUIRE(stack->max_size == 1);
                stack_destroy(stack);
            }
        }

        SECTION("creating a stack without options")
        {
            SECTION("max_size should be the default value")
            {
                stack_s* stack = stack_create(nullptr);
                REQUIRE(stack->max_size == STACK_DEFAULT_MAX_SIZE);
                stack_destroy(stack);
            }
        }

        SECTION("size should be 0 when creating a stack")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->size == 0);
            stack_destroy(stack);
        }

        SECTION("items should be allocated")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->items != NULL);
            stack_destroy(stack);
        }

        SECTION("stack should be empty")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->is_empty == true);
            stack_destroy(stack);
        }

        SECTION("stack should not be full")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->is_full == false);
            stack_destroy(stack);
        }
    }

    SECTION("push")
    {
        stack_s* stack = stack_create(nullptr);
        SECTION("increment size each time we push and stack is no longer empty")
        {
            int item = 0;
            stack_push(stack, &item);
            REQUIRE(stack->size == 1);
            REQUIRE(stack->is_empty == false);
        }

        SECTION("pushed item should be added")
        {
            int item = 1;
            stack_push(stack, &item);
            REQUIRE(*(int*)stack->items[0] == 1);
        }

        SECTION("able to push multiple items")
        {
            int items[] = { 1, 2, 3 };
            stack_push(stack, items);
            stack_push(stack, items + 1);
            stack_push(stack, items + 2);
            REQUIRE(*(int*)stack->items[0] == 1);
            REQUIRE(*(int*)stack->items[1] == 2);
            REQUIRE(*(int*)stack->items[2] == 3);
        }

        SECTION("when try to push to a full stack")
        {
            stack_options_s options;
            options.max_size = 2;
            stack_s* stackWithOptions = stack_create(&options);
            int items[] = { 1, 2, 3 };
            stack_push(stackWithOptions, items);
            stack_push(stackWithOptions, items + 1);
            stack_push(stackWithOptions, items + 2);
            REQUIRE(*(int*)stackWithOptions->items[0] == 1);
            REQUIRE(*(int*)stackWithOptions->items[1] == 2);
            stack_destroy(stackWithOptions);
        }

        SECTION("stack should be full when reaching its max size")
        {
            stack_options_s options;
            options.max_size = 2;
            stack_s* stackWithOptions = stack_create(&options);
            int items[] = { 1, 2, 3 };
            stack_push(stackWithOptions, items);
            REQUIRE(stackWithOptions->is_full == false);

            stack_push(stackWithOptions, items + 1);
            REQUIRE(stackWithOptions->is_full == true);
            REQUIRE(stackWithOptions->size == 2);

            stack_push(stackWithOptions, items + 2);
            REQUIRE(stackWithOptions->is_full == true);

            stack_pop(stackWithOptions);
            REQUIRE(stackWithOptions->is_full == false);
            stack_destroy(stackWithOptions);
        }
        stack_destroy(stack);
    }

    SECTION("pop")
    {
        stack_s* stack = stack_create(nullptr);
        SECTION("should decrements the size by 1")
        {
            int item = 1;
            stack_push(stack, &item);
            void* poppedItem = stack_pop(stack);
            REQUIRE(*(int*)poppedItem == 1);
            REQUIRE(stack->size == 0);

        }

        SECTION("stack should be empty when we pop all items")
        {
            int item = 1;
            stack_push(stack, &item);
            stack_pop(stack);
            REQUIRE(stack->is_empty == true);
        }

        SECTION("should return last pushed item")
        {
            int item1 = 1, item2 = 2;
            stack_push(stack, &item1);
            stack_push(stack, &item2);
            void* poppedItem = stack_pop(stack);
            REQUIRE(*(int*)poppedItem == 2);
        }

        SECTION("pop an empty stack should return NULL")
        {
            void* item = stack_pop(stack);
            REQUIRE(item == NULL);
        }

        SECTION("pop an empty stack do nothing")
        {
            stack_pop(stack);
            REQUIRE(stack->size == 0);
        }
        stack_destroy(stack);
    }

    SECTION("peek")
    {
        stack_s* stack = stack_create(nullptr);
        SECTION("peek top item without removing it")
        {
            int item = 1;
            stack_push(stack, &item);
            int v = *(int*)stack_peek(stack);
            REQUIRE(v == 1);
            REQUIRE(*(int*)stack->items[0] == 1);
        }

        SECTION("return null for empty stack")
        {
            void* vptr = stack_peek(stack);
            REQUIRE(vptr == NULL);
        }
        stack_destroy(stack);
    }

    SECTION("destroy")
    {
        SECTION("stack should be destroyed")
        {
            stack_s* stack = stack_create(nullptr);
            stack_destroy(stack);
            SUCCEED();
        }
    }
}


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
            }
        }

        SECTION("creating a stack without options")
        {
            SECTION("max_size should be the default value")
            {
                stack_s* stack = stack_create(nullptr);
                REQUIRE(stack->max_size == STACK_DEFAULT_MAX_SIZE);
            }
        }

        SECTION("size should be 0 when creating a stack")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->size == 0);
        }

        SECTION("items should be allocated")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->items != NULL);
        }

        SECTION("stack should be empty")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->is_empty == true);
        }

        SECTION("stack should not be full")
        {
            stack_s* stack = stack_create(nullptr);
            REQUIRE(stack->is_full == false);
        }
    }

    SECTION("push")
    {
        SECTION("increment size each time we push and stack is no longer empty")
        {
            stack_s* stack = stack_create(nullptr);
            int item = 0;
            stack_push(stack, &item);
            REQUIRE(stack->size == 1);
            REQUIRE(stack->is_empty == false);
        }

        SECTION("pushed item should be added")
        {
            stack_s* stack = stack_create(nullptr);
            int item = 1;
            stack_push(stack, &item);
            REQUIRE(*(int*)stack->items[0] == 1);
        }

        SECTION("able to push multiple items")
        {
            stack_s* stack = stack_create(nullptr);
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
            stack_s* stack = stack_create(&options);
            int items[] = { 1, 2, 3 };
            stack_push(stack, items);
            stack_push(stack, items + 1);
            stack_push(stack, items + 2);
            REQUIRE(*(int*)stack->items[0] == 1);
            REQUIRE(*(int*)stack->items[1] == 2);
        }

        SECTION("stack should be full when reaching its max size")
        {
            stack_options_s options;
            options.max_size = 2;
            stack_s* stack = stack_create(&options);
            int items[] = { 1, 2, 3 };
            stack_push(stack, items);
            REQUIRE(stack->is_full == false);

            stack_push(stack, items + 1);
            REQUIRE(stack->is_full == false);

            stack_push(stack, items + 2);
            REQUIRE(stack->is_full == true);

            stack_pop(stack);
            REQUIRE(stack->is_full == false);
        }
    }

    SECTION("pop")
    {
        SECTION("should decrements the size by 1")
        {
            stack_s* stack = stack_create(nullptr);
            int item = 1;
            stack_push(stack, &item);
            void* poppedItem = stack_pop(stack);
            REQUIRE(*(int*)poppedItem == 1);
            REQUIRE(stack->size == 0);
        }

        SECTION("stack should be empty when we pop all items")
        {
            stack_s* stack = stack_create(nullptr);
            int item = 1;
            stack_push(stack, &item);
            stack_pop(stack);
            REQUIRE(stack->is_empty == true);
        }

        SECTION("should return last pushed item")
        {
            stack_s* stack = stack_create(nullptr);
            int item1 = 1, item2 = 2;
            stack_push(stack, &item1);
            stack_push(stack, &item2);
            void* poppedItem = stack_pop(stack);
            REQUIRE(*(int*)poppedItem == 2);
        }

        SECTION("pop an empty stack should return NULL")
        {
            stack_s* stack = stack_create(nullptr);
            void* item = stack_pop(stack);
            REQUIRE(item == NULL);
        }

        SECTION("pop an empty stack do nothing")
        {
            stack_s* stack = stack_create(nullptr);
            stack_pop(stack);
            REQUIRE(stack->size == 0);
        }
    }

    SECTION("peek")
    {
        SECTION("peek top item without removing it")
        {
            stack_s* stack = stack_create(nullptr);
            int item = 1;
            stack_push(stack, &item);
            int v = *(int*)stack_peek(stack);
            REQUIRE(v == 1);
            REQUIRE(*(int*)stack->items[0] == 1);
        }

        SECTION("return null for empty stack")
        {
            stack_s* stack = stack_create(nullptr);
            void* vptr = stack_peek(stack);
            REQUIRE(vptr == NULL);
        }
    }
}

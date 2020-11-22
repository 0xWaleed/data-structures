
#include <catch2/catch.hpp>
#include <stack.h>

TEST_CASE("stack")
{
    SECTION("creating")
    {
        SECTION("create stack with given options")
        {
            stack_options_s stack_options;
            stack_options.max_size = 1;
            stack_s* stack =  stack_create(&stack_options);
            REQUIRE(stack->max_size == 1);
        }
    }

    SECTION("inserting")
    {

    }

    SECTION("removing")
    {

    }

    SECTION("destroying")
    {

    }
}

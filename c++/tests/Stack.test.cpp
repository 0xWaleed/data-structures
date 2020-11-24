#include <catch2/catch.hpp>
#include <Stack.hpp>

TEST_CASE("Stack")
{
    SECTION("initialization")
    {
        SECTION("should be empty")
        {
            Stack s;
            REQUIRE(s.isEmpty() == true);
        }

        SECTION("should not be full")
        {
            Stack s;
            REQUIRE(s.isFull() == false);
        }

        SECTION("size should be zero")
        {
            Stack s;
            REQUIRE(s.size() == 0);
        }

        SECTION("default max size should be 64")
        {
            Stack s;
            REQUIRE(s.maxSize() == 64);
        }

        SECTION("max size can be changed")
        {
            Stack s(2);
            REQUIRE(s.maxSize() == 2);
        }
    }

    SECTION("push")
    {
        SECTION("should increment the size")
        {
            Stack s;
            s.push(5);
            REQUIRE(s.size() == 1);
        }

        SECTION("should push the exact item")
        {
            Stack s;
            s.push(5);
            REQUIRE(s.peek() == 5);
        }

        SECTION("should push multiple items")
        {
            Stack s;
            s.push(5);
            s.push(55);
            s.push(555);
            REQUIRE(s.peek() == 555);
        }

        SECTION("should not push when stack is full")
        {
            Stack s(2);
            s.push(5);
            s.push(55);
            s.push(555);
            REQUIRE(s.peek() == 55);
            REQUIRE(s.size() == 2);
        }
    }

    SECTION("pop")
    {
        SECTION("decrements the size")
        {
            Stack s;
            s.push(5);
            s.push(55);
            s.push(555);
            s.pop();
            REQUIRE(s.size() == 2);
        }

        SECTION("should not decrement the size of empty stack and return default value")
        {
            Stack s;
            int value = s.pop();
            REQUIRE(s.size() == 0);
            REQUIRE(value == 0);
        }

        SECTION("return last pushed item")
        {
            Stack s;
            s.push(5);
            s.push(55);
            s.push(555);
            REQUIRE(s.pop() == 555);
        }
    }

    SECTION("peek")
    {
        SECTION("return last pushed item without removing it")
        {
            Stack s;
            s.push(5);
            s.push(55);
            s.push(555);
            REQUIRE(s.peek() == 555);
            REQUIRE(s.size() == 3);
            REQUIRE(s.pop() == 555);
        }

        SECTION("return default value when stack is empty")
        {
            Stack<int> s;
            REQUIRE(s.peek() == int());
        }
    }

    SECTION("is empty")
    {
        SECTION("should not be empty when stack has item(s)")
        {
            Stack s;
            s.push(5);
            REQUIRE(s.isEmpty() == false);
        }

        SECTION("should be empty when removing all items from stack")
        {
            Stack s;
            s.push(5);
            s.pop();
            REQUIRE(s.isEmpty() == true);
        }
    }

    SECTION("is full")
    {
        SECTION("stack should be full when size == max size")
        {
            Stack s(2);
            s.push(5);
            s.push(500);
            REQUIRE(s.isFull() == true);
        }

        SECTION("stack should not be empty when removing item")
        {
            Stack s(2);
            s.push(5);
            s.push(500);
            s.pop();
            REQUIRE(s.isFull() == false);
        }
    }
}


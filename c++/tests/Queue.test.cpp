#include <catch2/catch.hpp>
#include <Queue.hpp>

TEST_CASE("Queue")
{
    SECTION("initialize")
    {
        Queue<int> q(5);
        SECTION("size should be 0")
        {
            REQUIRE(q.size() == 0);
        }

        SECTION("capacity should return from constructor")
        {
            REQUIRE(q.capacity() == 5);
        }
    }

    SECTION("enqueue")
    {
        Queue<int> q(3);
        SECTION("should able to add an item and return true")
        {
            REQUIRE(q.enqueue(2) == true);
        }

        SECTION("size should be incremented")
        {
            q.enqueue(5);
            REQUIRE(q.size() == 1);

            q.enqueue(5);
            REQUIRE(q.size() == 2);

            q.enqueue(5);
            REQUIRE(q.size() == 3);
        }

        SECTION("should not add to full queue and return false")
        {
            q.enqueue(5);
            q.enqueue(5);
            q.enqueue(5);
            REQUIRE(q.enqueue(2) == false);
        }

        SECTION("able to add to full queue after removing an item")
        {
            q.enqueue(5);
            q.enqueue(5);
            q.enqueue(5);
            q.dequeue();
            REQUIRE(q.enqueue(2) == true);
        }
    }

    SECTION("dequeue")
    {
        Queue<int> q(3);
        q.enqueue(5);
        q.enqueue(4);
        q.enqueue(3);

        SECTION("return the first added item")
        {
            REQUIRE(q.dequeue() == 5);
            REQUIRE(q.dequeue() == 4);
            REQUIRE(q.dequeue() == 3);
        }

        SECTION("size should be decremented")
        {
            q.dequeue();
            REQUIRE(q.size() == 2);
            q.dequeue();
            REQUIRE(q.size() == 1);
            q.dequeue();
            REQUIRE(q.size() == 0);
        }
    }

    SECTION("peek")
    {

    }
}


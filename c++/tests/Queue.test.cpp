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
            REQUIRE(q.size() == 3);
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

        SECTION("return default value when queue empty")
        {
            Queue<int> queue(3);
            REQUIRE(queue.dequeue() == 0);
        }

        SECTION("size should not decremented when queue empty")
        {
            Queue<int> queue(3);
            queue.dequeue();
            REQUIRE(queue.size() == 0);
        }
    }

    SECTION("peek")
    {
        Queue<int> q(3);
        q.enqueue(1);
        q.enqueue(2);

        SECTION("should return first added item without removing it")
        {
            REQUIRE(q.peek() == 1);
            REQUIRE(q.size() == 2);
        }

        SECTION("should return default value when the queue is empty")
        {
            REQUIRE(Queue<int>(1).peek() == 0);
        }
    }

    SECTION("copy semantic")
    {
        SECTION("constructor")
        {
            Queue<int> q(5);
            Queue<int> qCopy = q;
            q.enqueue(2);
            REQUIRE(qCopy.size() == 0);
            qCopy.dequeue();
            REQUIRE(q.size() == 1);
        }

        SECTION("operator")
        {
            Queue<int> q(5);
            Queue<int> qCopy(5);
            qCopy = q;
            q.enqueue(2);
            REQUIRE(qCopy.size() == 0);
            qCopy.dequeue();
            REQUIRE(q.size() == 1);
        }
    }

    SECTION("move semantic")
    {
        SECTION("constructor")
        {
            Queue<int> q(5);
            q.enqueue(2);
            Queue<int> qCopy = std::move(q);
            REQUIRE(qCopy.size() == 1);
            qCopy.enqueue(3);
            q.~Queue();
            REQUIRE(qCopy.size() == 2);
            REQUIRE(qCopy.dequeue() == 2);
            REQUIRE(qCopy.dequeue() == 3);
            SUCCEED();
        }

        SECTION("operator")
        {
            Queue<int> q(5);
            q.enqueue(2);
            Queue<int> qCopy(1);
            qCopy = std::move(q);
            REQUIRE(qCopy.size() == 1);
            qCopy.enqueue(3);
            q.~Queue();
            REQUIRE(qCopy.size() == 2);
            REQUIRE(qCopy.dequeue() == 2);
            REQUIRE(qCopy.dequeue() == 3);
            SUCCEED();
        }
    }
}


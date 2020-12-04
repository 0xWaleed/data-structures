#include <catch2/catch.hpp>
#include <queue.h>

TEST_CASE("queue")
{
    SECTION("initialize")
    {
        queue_s* q = queue_create(5);
        SECTION("size should be 0")
        {
            REQUIRE(q->size == 0);
        }

        SECTION("values should be nullptr")
        {
            REQUIRE(q->values == nullptr);
        }

        SECTION("capacity")
        {
            REQUIRE(q->capacity == 5);
        }
    }

    SECTION("enqueue")
    {
        queue_s* q = queue_create(3);

        SECTION("should allocate space if #values is nullptr")
        {
            int value = 0;
            queue_enqueue(q, &value);
            REQUIRE(q->values != nullptr);
        }

        SECTION("should able to add the value and return true")
        {
            int value = 1337;
            REQUIRE(queue_enqueue(q, &value) == true);
            REQUIRE(*reinterpret_cast<int*>(q->values[0]) == 1337);
        }

        SECTION("increment size")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            REQUIRE(q->size == 1);
        }

        SECTION("add multiple items")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            queue_enqueue(q, &value);
            queue_enqueue(q, &value);
            REQUIRE(*reinterpret_cast<int*>(q->values[0]) == 1337);
            REQUIRE(*reinterpret_cast<int*>(q->values[1]) == 1337);
            REQUIRE(*reinterpret_cast<int*>(q->values[2]) == 1337);
        }

        SECTION("adding to queue when size == capacity")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            queue_enqueue(q, &value);
            queue_enqueue(q, &value);
            REQUIRE(q->size == 3);
            REQUIRE(queue_enqueue(q, &value) == false);
            REQUIRE(q->size == 3);
        }

        SECTION("able to add to full queue that after calling dequeue")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            queue_enqueue(q, &value);
            queue_enqueue(q, &value);
            queue_dequeue(q);
            REQUIRE(queue_enqueue(q, &value) == true);
            REQUIRE(q->size == 3);
        }
    }

    SECTION("peek")
    {
        queue_s* q = queue_create(5);
        int v[] = { 2, 4, 6 };
        queue_enqueue(q, &v[0]);
        queue_enqueue(q, &v[1]);
        queue_enqueue(q, &v[2]);

        SECTION("get first added item without remove it")
        {
            void* r = queue_peek(q);
            REQUIRE(q->size == 3);
            REQUIRE(*reinterpret_cast<int*>(r) == 2);
        }

        SECTION("peek after dequeue")
        {
            queue_dequeue(q);
            void* r = queue_peek(q);
            REQUIRE(*reinterpret_cast<int*>(r) == 4);

            queue_dequeue(q);
            r = queue_peek(q);
            REQUIRE(*reinterpret_cast<int*>(r) == 6);
        }
    }

    SECTION("dequeue")
    {
        queue_s* q = queue_create(5);
        int values[] = { 2, 4, 6 };
        queue_enqueue(q, &values[0]);
        queue_enqueue(q, &values[1]);
        queue_enqueue(q, &values[2]);

        SECTION("return first in items in order")
        {
            void* r = queue_dequeue(q);
            REQUIRE(*reinterpret_cast<int*>(r) == 2);
            r = queue_dequeue(q);
            REQUIRE(*reinterpret_cast<int*>(r) == 4);
            r = queue_dequeue(q);
            REQUIRE(*reinterpret_cast<int*>(r) == 6);
        }

        SECTION("should decrement the size")
        {
            queue_dequeue(q);
            REQUIRE(q->size == 2);
            queue_dequeue(q);
            REQUIRE(q->size == 1);
            queue_dequeue(q);
            REQUIRE(q->size == 0);
        }
    }
}


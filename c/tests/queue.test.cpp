#include <catch2/catch.hpp>
#include <queue.h>

TEST_CASE("queue")
{
    SECTION("initialize")
    {
        queue_s* q = queue_create();
        SECTION("size should be 0")
        {
            REQUIRE(q->size == 0);
        }

        SECTION("values should be nullptr")
        {
            REQUIRE(q->values == nullptr);
        }
    }

    SECTION("enqueue")
    {
        queue_s* q = queue_create();

        SECTION("should allocate space if #values is nullptr")
        {
            int value = 0;
            queue_enqueue(q, &value);
            REQUIRE(q->values != nullptr);
        }

        SECTION("should able to add the value")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            REQUIRE(*reinterpret_cast<int*>(q->values[0]) == 1337);
        }

        SECTION("increment size")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            REQUIRE(q->size == 1);
        }

        SECTION("should not move values if size still below the block")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            void** prevValues = q->values;
            queue_enqueue(q, &value);
            REQUIRE(q->values == prevValues);
        }

        SECTION("should move values if size still size and block has no reminder")
        {
            int value = 1337;
            queue_enqueue(q, &value);
            void** prevValues = q->values;
            for (int i = 0; i < QUEUE_BLOCK_SIZE; ++i)
            {
                queue_enqueue(q, &value);
            }

            REQUIRE(q->values != prevValues);

            for (int i = 0; i < q->size; ++i)
            {
                REQUIRE(*reinterpret_cast<int*>(q->values[i]) == 1337);
            }
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
    }

    SECTION("peek")
    {

    }

    SECTION("dequeue")
    {

    }
}


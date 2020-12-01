#include <catch2/catch.hpp>
#include <link-list.h>
#include <clist.h>


TEST_CASE("link-list")
{
    SECTION("initialize")
    {
        linklist_s* l = linklist_create();
        SECTION("size should be 0")
        {
            REQUIRE(l->size == 0);
        }

        SECTION("head should be NULL")
        {
            REQUIRE(l->head == nullptr);
        }

        SECTION("tail should be NULL")
        {
            REQUIRE(l->tail == nullptr);
        }
    }

    SECTION("add")
    {
        linklist_s* l = linklist_create();



        SECTION("first element should be added to head and tail")
        {
            int value = 5;
            linklist_add(l, &value);
            REQUIRE(l->head != nullptr);
            REQUIRE(l->tail != nullptr);
            REQUIRE(*reinterpret_cast<int*>(l->head->value) == 5);
            REQUIRE(*reinterpret_cast<int*>(l->tail->value) == 5);
        }

        SECTION("should not change head when adding first element")
        {
            int values[] = { 5, 6 };
            linklist_add(l, &values[0]);
            linklist_add(l, &values[1]);
            REQUIRE(l->head != nullptr);
            REQUIRE(*reinterpret_cast<int*>(l->head->value) == 5);
        }

        SECTION("second element should be added to tail only")
        {
            int values[] = { 5, 6 };
            linklist_add(l, &values[0]);
            linklist_add(l, &values[1]);
            REQUIRE(l->tail != nullptr);
            REQUIRE(*reinterpret_cast<int*>(l->tail->value) == 6);
        }

        SECTION("tail should be point to last node")
        {
            int values[] = { 5, 6, 7 };
            linklist_add(l, &values[0]);
            REQUIRE(*reinterpret_cast<int*>(l->tail->value) == 5);
            linklist_add(l, &values[1]);
            REQUIRE(*reinterpret_cast<int*>(l->tail->value) == 6);
            linklist_add(l, &values[2]);
            REQUIRE(*reinterpret_cast<int*>(l->tail->value) == 7);
        }

        SECTION("multiple element")
        {
            int values[] = {
                    1, 2, 3
            };
            linklist_add(l, &values[0]);
            linklist_add(l, &values[1]);
            linklist_add(l, &values[2]);

            REQUIRE(*reinterpret_cast<int*>(l->head->value) == values[0]);
            REQUIRE(*reinterpret_cast<int*>(l->head->next->value) == values[1]);
            REQUIRE(*reinterpret_cast<int*>(l->head->next->next->value) == values[2]);
        }

        SECTION("node next should be NULL")
        {
            int value = 5;
            linklist_add(l, &value);
            REQUIRE(l->head->next == nullptr);
        }
    }

    SECTION("traverse")
    {
        linklist_s* l = linklist_create();
        SECTION("list that has multiple nodes")
        {
            int values[] = {
                    1, 2, 3, 4, 5
            };
            linklist_add(l, &values[0]);
            linklist_add(l, &values[1]);
            linklist_add(l, &values[2]);
            linklist_add(l, &values[3]);
            linklist_add(l, &values[4]);
            clist_s* list = clist_create(16);
            linklist_traverse(l->head, list);

            REQUIRE(list->size == 5);
            REQUIRE(*reinterpret_cast<int*>(list->values[0]) == 1);
            REQUIRE(*reinterpret_cast<int*>(list->values[1]) == 2);
            REQUIRE(*reinterpret_cast<int*>(list->values[2]) == 3);
            REQUIRE(*reinterpret_cast<int*>(list->values[3]) == 4);
            REQUIRE(*reinterpret_cast<int*>(list->values[4]) == 5);
        }

        SECTION("empty list")
        {
            clist_s* list = clist_create(16);
            linklist_traverse(l->head, list);
            REQUIRE(list->size == 0);
        }
    }

    SECTION("find")
    {
        linklist_s* linklist = linklist_create();
        SECTION("with existent value")
        {
            int value = 5;
            linklist_add(linklist, &value);

            linklist_node_s* node = linklist_find(linklist, [](void* value) -> bool {
                return *reinterpret_cast<int*>(value) == 5;
            });

            REQUIRE(node != nullptr);
            REQUIRE(*reinterpret_cast<int*>(node->value) == 5);
        }

        SECTION("with not existent value")
        {
            int value = 5;
            linklist_add(linklist, &value);

            linklist_node_s* node = linklist_find(linklist, [](void*) -> bool {
                return false;
            });

            REQUIRE(node == nullptr);
        }
    }

    SECTION("remove")
    {
        linklist_s* linklist = linklist_create();
        clist_s* clist = clist_create(8);
        int values[] = { 2, 4, 6 };
        linklist_add(linklist, &values[0]);
        linklist_add(linklist, &values[1]);
        linklist_add(linklist, &values[2]);

        SECTION("delete first node")
        {
            linklist_remove(linklist, [](void* value)-> bool {
                return *reinterpret_cast<int*>(value) == 2;
            });
            linklist_traverse(linklist->head, clist);
            REQUIRE(clist->size == 2);
            REQUIRE(*reinterpret_cast<int*>(clist->values[0]) == 4);
            REQUIRE(*reinterpret_cast<int*>(clist->values[1]) == 6);
        }

        SECTION("delete middle node")
        {
            linklist_remove(linklist, [](void* value)-> bool {
                return *reinterpret_cast<int*>(value) == 4;
            });
            linklist_traverse(linklist->head, clist);
            REQUIRE(clist->size == 2);
            REQUIRE(*reinterpret_cast<int*>(clist->values[0]) == 2);
            REQUIRE(*reinterpret_cast<int*>(clist->values[1]) == 6);
        }

        SECTION("delete last node")
        {
            linklist_remove(linklist, [](void* value)-> bool {
                return *reinterpret_cast<int*>(value) == 6;
            });
            linklist_traverse(linklist->head, clist);
            REQUIRE(clist->size == 2);
            REQUIRE(*reinterpret_cast<int*>(clist->values[0]) == 2);
            REQUIRE(*reinterpret_cast<int*>(clist->values[1]) == 4);
        }
    }
}


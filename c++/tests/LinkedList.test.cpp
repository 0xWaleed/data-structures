#include <catch2/catch.hpp>
#include <LinkedList.hpp>

TEST_CASE("LinkedList")
{
    SECTION("initialize")
    {
        SECTION("size should be zero")
        {
            LinkedList l;
            REQUIRE(l.size() == 0);
        }
    }

    SECTION("insert")
    {
        SECTION("insert to first available node")
        {
            SECTION("first item will be assigned to head")
            {
                LinkedList l;
                l.insert(5);
                REQUIRE(l.head()->value == 5);
            }

            SECTION("multiple items")
            {
                LinkedList l;
                l.insert(5);
                l.insert(6);
                l.insert(7);
                l.insert(8);
                auto expected = std::vector<int>{
                        5, 6, 7, 8
                };
                auto values = l.head()->traverse();
                REQUIRE_THAT(values, Catch::Matchers::Equals(expected));
            }

            SECTION("size should be incremented")
            {
                LinkedList l;
                REQUIRE(l.size() == 0);
                l.insert(5);
                REQUIRE(l.size() == 1);
                l.insert(5);
                REQUIRE(l.size() == 2);
                l.insert(5);
                REQUIRE(l.size() == 3);
            }
        }

        SECTION("insert at the beginning")
        {
            SECTION("first item become head")
            {
                LinkedList l;
                l.insertAtBeginning(5);
                REQUIRE(l.head() != nullptr);
                REQUIRE(l.head()->value == 5);
            }

            SECTION("head should become second when it points to a node")
            {
                LinkedList l;
                l.insertAtBeginning(5);
                l.insertAtBeginning(6);
                REQUIRE(l.head() != nullptr);
                const std::vector<int>& expected = std::vector<int>{ 6, 5 };
                REQUIRE_THAT(l.head()->traverse(), Catch::Matchers::Equals(expected));
            }

            SECTION("size should be incremented")
            {
                LinkedList l;
                REQUIRE(l.size() == 0);
                l.insertAtBeginning(1);
                REQUIRE(l.size() == 1);
                l.insertAtBeginning(1);
                REQUIRE(l.size() == 2);
                l.insertAtBeginning(1);
                REQUIRE(l.size() == 3);
            }
        }


    }

    SECTION("find")
    {
        LinkedList l;
        l.insert(5);
        l.insert(6);
        l.insert(7);
        l.insert(8);
        SECTION("existent item")
        {
            SinglyNode<int>* node = l.find(5);
            REQUIRE(node->value == 5);
        }

        SECTION("non existent item")
        {
            SinglyNode<int>* node = l.find(100);
            REQUIRE(node == nullptr);
        }

        SECTION("empty link list")
        {
            SinglyNode<int>* singleNode = LinkedList().find(100);
            REQUIRE(singleNode == nullptr);
        }
    }

    SECTION("delete")
    {
        LinkedList l;
        l.insert(5);
        l.insert(6);
        l.insert(7);
        l.insert(8);

        SECTION("deleting first node")
        {
            l.deleteNodeByValue(5);
            auto expected = std::vector<int>{
                    6, 7, 8
            };
            REQUIRE_THAT(l.head()->traverse(), Catch::Matchers::Equals(expected));
        }

        SECTION("deleting node in the middle")
        {
            l.deleteNodeByValue(6);
            auto expected = std::vector<int>{
                    5, 7, 8
            };
            REQUIRE_THAT(l.head()->traverse(), Catch::Matchers::Equals(expected));
        }

        SECTION("deleting last element")
        {
            l.deleteNodeByValue(8);
            auto expected = std::vector<int>{
                    5, 6, 7
            };
            REQUIRE_THAT(l.head()->traverse(), Catch::Matchers::Equals(expected));
        }
    }
}

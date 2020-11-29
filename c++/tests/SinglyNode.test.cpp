#include <catch2/catch.hpp>
#include <SinglyNode.hpp>


TEST_CASE("SinglyNode")
{
    SECTION("initialize")
    {
        SECTION("next should be nullptr")
        {
            SinglyNode node;
            REQUIRE(node.next == nullptr);
        }

        SECTION("value is defaulted to its data type")
        {
            SinglyNode node;
            REQUIRE(node.value == 0);
        }
    }

    SECTION("traverse")
    {
        SinglyNode<int> head;
        head.value = 1;

        auto secondNode = std::make_unique<SinglyNode<int>>();
        secondNode->value = 2;
        head.next = std::move(secondNode);

        auto thirdNode = std::make_unique<SinglyNode<int>>();
        thirdNode->value = 3;

        head.next->next = std::move(thirdNode);

        auto values = head.traverse();
        auto expected = std::vector<int>{
                1, 2, 3
        };

        REQUIRE_THAT(values, Catch::Matchers::Equals(expected));
    }
}

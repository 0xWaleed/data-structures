#include <iostream>
#include <LinkedList.hpp>

int main()
{
    LinkedList<int> l;

    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);

    auto values = l.head()->traverse();

    for (auto& v: values)
    {
        std::cout << v << std::endl;
    }

    l.deleteNodeByValue(3);
    l.deleteNodeByValue(4);

    values = l.head()->traverse();
    for (auto& v: values)
    {
        std::cout << v << std::endl;
    }

    return 0;
}

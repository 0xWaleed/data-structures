

#ifndef SINGLYNODE_HPP
#define SINGLYNODE_HPP

#include <vector>

template<typename T = int>
class SinglyNode
{
public:
    std::unique_ptr<SinglyNode> next{};
    T value{};

    std::vector<T> traverse()
    {
        std::vector<T> list;

        list.push_back(value);

        if (this->next == nullptr)
        {
            return list;
        }

        std::vector<T> vector = next->traverse();

        for (auto& item: vector)
        {
            list.push_back(item);
        }

        return list;
    }
};

#endif //SINGLYNODE_HPP

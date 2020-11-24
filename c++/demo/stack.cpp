#include <iostream>
#include <Stack.hpp>

int main()
{
    int maxSize = 16;
    Stack<std::string> stack(maxSize);

    for (int i = 1; i <= maxSize; ++i)
    {
        stack.push("Item " + std::to_string(i));
    }

    std::cout << "size of stack before: " << stack.size() << std::endl;

    size_t size = stack.size();

    for (int i = 0; i < size; ++i)
    {
        std::cout << stack.pop() << std::endl;
    }

    std::cout << "size of stack after: " << stack.size() << std::endl;
}


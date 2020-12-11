#include <iostream>
#include <Stack.hpp>
#include <memory>
#include <string>


int main()
{
    int maxSize = 100;
    Stack<std::string> stack;

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


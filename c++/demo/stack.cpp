#include <iostream>

#include <Stack.hpp>
int main()
{
    Stack<std::string> stack;

    stack.push("First");
    stack.push("Second");
    stack.push("Third");
    stack.push("Forth");

    std::cout << "size of stack before: " << stack.size() << std::endl;

    size_t size = stack.size();

    for (int i = 0; i < size; ++i)
    {
        std::cout << stack.pop() << std::endl;
    }

    std::cout << "size of stack after: " << stack.size() << std::endl;
}


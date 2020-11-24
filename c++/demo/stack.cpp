#include <iostream>

int main()
{
    std::unique_ptr<int[]> s = std::make_unique<int[]>(5);
    s[0] = 1;
}


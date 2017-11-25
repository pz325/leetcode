#include <vector>
#include <iostream>

void printV(const std::vector<int>& v) 
{
    for (auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

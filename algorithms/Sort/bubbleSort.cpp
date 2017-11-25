#include <vector>
#include <iostream>

#include "util.hpp"

void bubbleSort(std::vector<int> &v)
{
    const int l = v.size();
    for (int i = 0; i < l; ++i)
    {
        bool changed = false;
        for (int j = i; j < l-i; ++j)
        {
            if (v[j] > v[j+1])
            {
                int tmp = v[j+1];
                v[j+1] = v[j];
                v[j] = tmp;
                changed = true;
            }
        }
        
        if (!changed)
        {
            break;
        }

        printV(v);        
    }
}

int main()
{
    std::vector<int> v { 9, 2, 3, 6, 5, 10, 7, 11, 8};
    bubbleSort(v);
    printV(v);
    return 0;
}
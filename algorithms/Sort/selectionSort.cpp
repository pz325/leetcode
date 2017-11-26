#include "util.hpp"

void selectionSort(std::vector<int>& v)
{
    int sortedUpperIndex = -1;
    while (sortedUpperIndex < (int)v.size())
    {
        int minIndex = sortedUpperIndex + 1;
        int min = v[minIndex];
        for (int i = sortedUpperIndex+1; i < v.size(); ++i)
        {
            if (v[i] < min)
            {
                min = v[i];
                minIndex = i;
            }
        }

        ++sortedUpperIndex;
        if (minIndex == sortedUpperIndex)
        {
            continue;
        }
        
        v[minIndex] = v[sortedUpperIndex];
        v[sortedUpperIndex] = min;

        printV(v);
    }
}

int main()
{
    std::vector<int> v{9, 2, 3, 6, 5, 10, 7, 11, 8};
    selectionSort(v);
    printV(v);
    return 0;
}

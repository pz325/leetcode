#include "util.hpp"


void insertionSort(std::vector<int>& v)
{
    for(int i = 1; i < v.size(); ++i)
    {
        int valueToInsert = v[i];
        int j = i - 1;
        for(; j >= 0; --j)
        {
            if (v[j] > valueToInsert)
            {
                v[j+1] = v[j];
            }
            else{
                break;
            }
        }

        v[j+1] = valueToInsert;
        printV(v);
    }
}

int main()
{
    std::vector<int> v{9, 2, 3, 6, 5, 10, 7, 11, 8};
    insertionSort(v);
    printV(v);
    return 0;
}
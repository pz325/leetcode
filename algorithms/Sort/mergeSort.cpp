#include "util.hpp"
#include <algorithm>

// use a global tmp swap buffer
std::vector<int> tmp;

void merge(std::vector<int>&v, int l, int m, int r)
{
    std::cout << "before merge ";
    std::cout << l << " " << m << " " << r << std::endl;
    for (int x = l; x <= r; ++x)
    {
        std::cout << v[x] << " ";
    }
    std::cout << std::endl;

    int i = l;
    int j = m+1;
    int k = l;
    while (i <= m && j <= r)
    {
        if (v[i] <= v[j])
        {
            tmp[k] = v[i];
            ++i;
        }
        else
        {
            tmp[k] = v[j];
            ++j;
        }
        ++k;
    }

    while (i <= m)
    {
        tmp[k] = v[i];
        ++k;
        ++i;
    }
    
    while (j <= r)
    {
        tmp[k] = v[j];
        ++k;
        ++j;
    }

    // std::cout << "here" << std::endl;
    std::copy(std::begin(tmp)+l, std::begin(tmp)+r+1, std::begin(v)+l);
    std::cout << "after merge" << std::endl;
    for (int x = l; x <= r; ++x)
    {
        std::cout << v[x] << " ";
    }
    std::cout << std::endl;
}

void mergeSort(std::vector<int> &v, int l, int r)
{
    std::cout << "mergeSort ";
    std::cout << l << " " << r << std::endl;
    if (r > l)
    {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void mergeSort(std::vector<int> &v)
{
    tmp.reserve(v.size());
    std::copy(std::begin(v), std::end(v), std::begin(tmp));
    mergeSort(v, 0, v.size()-1);
}

int main()
{
    std::vector<int> v{9, 2, 3, 6, 5, 10, 7, 11, 8};
    mergeSort(v);
    printV(v);
    return 0;
}

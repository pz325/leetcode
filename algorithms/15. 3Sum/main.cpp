/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printV(const std::vector<int> &v)
{
    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void printVs(const std::vector<std::vector<int>>& vs)
{
    for (auto v: vs)
    {
        printV(v);
    }
}

class Solution
{
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ret;
        std::sort(std::begin(nums), std::end(nums));

        std::vector<int> v {0, 0, 0};
        int tmp = 0;
        for (auto i = std::begin(nums); i < std::end(nums);)
        {
            tmp = *i;
            auto j = i + 1;
            auto k = std::end(nums) - 1;
            while (j < k)
            {
                int sum = *i + *j + *k;
                
                if (sum > 0)
                {
                    --k;
                }
                else if (sum < 0)
                {
                    ++j;
                }
                else
                {
                    v[0] = *i;
                    v[1] = *j;
                    v[2] = *k;
                    // three integer is in sequence, by skipping the repeated integer, we can ensure the uniqueness.
                    ret.push_back(v);
                    
                    // skip repeated 2nd integer
                    while (*j == v[1])
                    {
                        ++j;
                    }

                    // skip repeated 3rd integer
                    while (*k == v[2])
                    {
                        --k;
                    }
                }
            }

            ++i;
            // skip repeated 1st integer
            while (*i == tmp)
            {
                ++i;
            }
        }

        return ret;
    }
};

int main()
{
    std::vector<int> s{3, 0, -2, -1, 1, 2};
    Solution solution;
    auto ret = solution.threeSum(s);
    printVs(ret);
}
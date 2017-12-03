/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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

class Solution
{
  public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        std::sort(std::begin(nums), std::end(nums));
        int ret = 0;
        int minDiff = INT_MAX;
        for (auto i = std::begin(nums); i < std::end(nums);)
        {
            const int valueAtI = *i;
            auto j = i + 1;
            auto k = std::end(nums) - 1;
            int valueAtJ = *j;
            int valueAtK = *k;
            int sum = valueAtI + valueAtJ + valueAtK;

            while (j < k)
            {
                const int diff = abs(sum - target);
                printV({valueAtI, valueAtJ, valueAtK, sum, target, diff});
                if (diff < minDiff)
                {
                    ret = sum;
                    minDiff = diff;
                    std::cout << "find new min diff at ";
                    printV({valueAtI, valueAtJ, valueAtK, sum, target, diff});
                }

                if (minDiff == 0)
                {
                    return ret;
                }

                if ((target - sum) > 0)
                {
                    std::cout << "increase j" << std::endl;
                    ++j;
                    // skip repeated 2nd integer
                    while (j < k && *j == valueAtJ)
                    {
                        std::cout << "increase j" << std::endl;
                        ++j;
                    }
                }
                else
                {
                    std::cout << "decrease k" << std::endl;
                    --k;
                    // skip repeated 3rd integer
                    while (j < k && *k == valueAtK)
                    {
                        std::cout << "decrease k" << std::endl;
                        --k;
                    }
                }

                valueAtJ = *j;
                valueAtK = *k;
                sum = valueAtI + valueAtJ + valueAtK;
            }

            ++i;
            // skip repeated 1st integer
            while (i != std::end(nums) && *i == valueAtI)
            {
                ++i;
            }
        }

        return ret;
    }
};

int main()
{
    std::vector<int> s{1, 2, 4, 8, 16, 32, 64, 128};
    const int target = 82;
    Solution solution;
    const int ret = solution.threeSumClosest(s, target);
    std::cout << ret << std::endl;
}

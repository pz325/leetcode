/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Solution
{
  public:
    /**
     * this is the O(n logn) solution
     */ 
    int lengthOfLIS(const std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        std::vector<int> lengths;
        lengths.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            auto index = std::lower_bound(std::begin(lengths), std::end(lengths), nums[i]);
            if (index == lengths.end())
            {
                lengths.emplace_back(nums[i]);
            }
            else
            {
                *index = nums[i];
            }
            std::cout << nums[i] << std::endl;
            std::cout << "lengths:" << std::endl;
            for (auto l : lengths)
            {
                std::cout << l << " ";
            }
            std::cout << std::endl;
        }

        return lengths.size();
    }

    /**
     * This is DP soluton, O(n^2)
     */ 
    int lengthOfLIS_DP(const std::vector<int>& nums)
    {
        int ret = 1;
        if (nums.empty())
        {
            return 0;
        }


        std::vector<int> lengths;
        lengths.emplace_back(1);

        for(int i = 1; i < nums.size(); ++i)
        {
            int maxL = 0;
            bool toExtend = false;
            for(int j = 0; j < i; ++j)
            {
                if (nums[j] >= nums[i])
                {
                    continue;
                }

                toExtend = true;
                if (lengths[j] > maxL)
                {
                    maxL = lengths[j];
                }
            }

            if (toExtend)
            {
                int newL = maxL + 1;
                if (newL > ret) {
                    ret = newL;
                }

                lengths.emplace_back(newL);
            }
            else
            {
                lengths.emplace_back(1);
            }
        }

        return ret;
    }
};

int main()
{
    Solution solution;
    const std::vector<int> input{1, 3, 6, 7, 9, 4, 10, 5, 6};
    const int result = solution.lengthOfLIS(input);
    std::cout << result << std::endl;
    return 0;
}

/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0


Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <vector>
#include <algorithm>
#include <iostream>


class Solution
{
  public:
    double getMedian(const std::vector<int>& v) 
    {
        if (v.size() % 2 == 0) {
            const int index = v.size() / 2 - 1;
            return ((double)v[index] + (double)v[index+1]) / 2;
        } else {
            return v[v.size() / 2];
        }
        
    }

    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // merge two vector
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        // sort
        std::sort(nums1.begin(), nums1.end());

        // find median
        return getMedian(nums1);
    }
};

int main() {
    std::vector<int> nums1 { 1, 2 };
    std::vector<int> nums2 { 3, 4 };
    Solution solution;
    std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
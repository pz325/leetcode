/**
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <iostream>
#include <cinttypes>
#include <vector>
#include <math.h>

const int INT32_MAX_D_10 = INT32_MAX / 10;

class Solution
{
  public:
    int reverse(int x)
    {
        if (x == 0 || x > INT32_MAX) { 
            return 0;
        }

        bool isNegative = x < 0;
        if (isNegative) { x *= -1; }

        int ret = 0;
        while (x > 0) {
            if (ret > INT32_MAX_D_10)
            {
                return 0;
            }

            ret = ret * 10 + x % 10;
            x /= 10;
            
            std::cout << x << " " << ret << std::endl;
        }
        
        if (isNegative) { ret *= -1; }

        return ret;
    }
};

int main() {
    Solution solution;
    const int input = -2147483412;
    const int result = solution.reverse(input);
    std::cout << "result: " << result << std::endl;
    std::cout << INT32_MAX << std::endl;
    std::cout << INT32_MAX_D_10 << std::endl;
    return 0;
}
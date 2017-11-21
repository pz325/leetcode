/**
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
 
 */

#include <iostream>
#include <vector>

const std::vector<int> TEN_MAG = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        std::cout << "==== isPalindrome ====" << std::endl;
        if (x < 0) { return false; }
        if (0 <= x && x < 10) { return true; }

        int div = 1;
        while (x / div >= 10 ) {
            div *= 10;
        }

        while (x >= 10) {
            int tail = x % 10;
            int head = x / div;
            std::cout << x << " div: " << div << " head: " << head << " tail: " << tail << std::endl;
            if (tail != head) {
                return false;
            }

            // remove tail
            x /= 10;
            if (x < 10) { return true; }
            div /= 10;
            std::cout << "after removing tail, x: " << x << std::endl;

            // remove head
            x -= head * div;
            if (x == 0) { return true; }
            div /= 10;
            int numLeadingZeros = 0;
            while (x * TEN_MAG[numLeadingZeros] / div < 1) {
                std::cout << x << " " << numLeadingZeros << " " << (x * TEN_MAG[numLeadingZeros]) << " " << div << std::endl;
                ++numLeadingZeros;
            }
            div /= TEN_MAG[numLeadingZeros];

            std::cout << numLeadingZeros << std::endl;

            while (numLeadingZeros > 0) {
                if (x < 10 || x % 10 != 0)
                {
                    return false;
                }
                x /= 10;
                div /= 10;
                --numLeadingZeros;
            }

            std::cout << "after removing head, x: " << x << std::endl;
        }

        return true;
    }
};

int main() {
    Solution solution;
    const int y = 1000021;
    const bool rety = solution.isPalindrome(y);
    std::cout << rety << std::endl;

    return 0;
}
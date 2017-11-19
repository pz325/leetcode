/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

#include <string>
#include <iostream>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string ret;

        if (s.size() == 1) {
            return s;
        }

        for (int i = 1; i < s.size(); ++i) {
            std::string palindrome = findPalindrome(s, i);
            if (palindrome.size() > ret.size()) {
                ret = palindrome;
            }
        }

        if (ret.empty() && !s.empty()) {
            return s.substr(0, 1);
        } else {
            return ret;
        }
    }

private:
    std::string findPalindrome(const std::string& s, int i) 
    {
        std::cout << "\nfindPalindrome at " << i << std::endl;
        std::string ret;
        int palindromeStart = -1;
        int palindromeEnd = -1;
        bool foundEvenPalindrome = true;
        bool foundOddPalindrome = true;

        int x = i;
        int y = i;
        if (x < 0)
        {
            return ret;
        }

        while (x >= 1 && y <= s.size()-1)
        {
            // check even palindrome
            --x;
            std::cout << s[x] << " <> " << s[y] << std::endl;
            if (s[x] != s[y])
            {
                foundEvenPalindrome = false;
                std::cout << "stop finding even palindrome at " << x << " " << y << std::endl;
            }

            if (foundEvenPalindrome) {
                palindromeStart = x;
                palindromeEnd = y;
            }
            
            // check odd palidrome
            ++y;
            std::cout << s[x] << " <> " << s[y] << std::endl;
            if (s[x] != s[y])
            {
                foundOddPalindrome = false;
                std::cout << "stop finding odd palindrome at " << x << " " << y << std::endl;   
            }

            if (foundOddPalindrome) {
                palindromeStart = x;
                palindromeEnd = y;
            }

            if (!foundOddPalindrome && !foundEvenPalindrome) {
                std::cout << "stop finding palindrome at " << x << " " << y << std::endl;
                break;
            }   
        }

        if (palindromeStart != -1 && palindromeEnd != -1)
        {
            ret = s.substr(palindromeStart, palindromeEnd - palindromeStart + 1);
            std::cout << "found palindrome " << ret << " at " << i << " in " << s << std::endl << std::endl;
        }

        return ret;
    }
};

int main() {
    const std::string input = "bb";
    Solution solution;
    const std::string result = solution.longestPalindrome(input);
    std::cout << "\nresult: " << result << std::endl;
    return 0;
}

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
            std::string evenPalindrome = findEvenPalindrome(s, i);
            if (evenPalindrome.size() > ret.size()) {
                ret = evenPalindrome;
            }

            std::string oddPalindrome = findOddPalindrome(s, i);
            if (oddPalindrome.size() > ret.size()) {
                ret = oddPalindrome;
            }
        }

        return ret;
    }

private:
    /**
     * search for palindrome having even number of chars
     * search backward from index
     */ 
    std::string findEvenPalindrome(const std::string& s, int i)
    {
        std::cout << "findEvenPalindrome at " << i << std::endl;
        std::string ret;
        int palindromeStart = -1;
        int palindromeEnd = -1;

        int x = i - 1;
        int y = i;
        if (x < 0) {
            return ret;
        }

        while (x >= 0 && y < s.size()) {
            std::cout << s[x] << " <> " << s[y] << std::endl;
            if (s[x] != s[y]) {
                std::cout << "stop at" << x << " " << y << std::endl;
                break;
            }

            palindromeStart = x;
            palindromeEnd = y;
            --x;
            ++y; 
        }

        if (palindromeStart != -1 && palindromeEnd != -1) {
            ret = s.substr(palindromeStart, palindromeEnd-palindromeStart+1);
            std::cout << ret << std::endl;
        }

        return ret;
    } 
    
    /** 
     * search for palindrome having odd number of chars
     */ 
    std::string findOddPalindrome(const std::string& s, int i)
    {
        std::cout << "findOddPalindrome at " << i << std::endl;
        std::string ret;
        int palindromeStart = -1;
        int palindromeEnd = -1;

        int x = i - 1;
        int y = i + 1;
        if (x < 0 || y >= s.size()) {
            return ret;
        }

        while (x >= 0 && y < s.size()) {
            std::cout << s[x] << " <> " << s[y] << std::endl;
            if (s[x] != s[y]) {
                std::cout << "stop at " <<  x << " " << y << std::endl;
                break;
            }

            palindromeStart = x;
            palindromeEnd = y;
            --x;
            ++y;
        }

        if (palindromeStart != -1 && palindromeEnd != -1)
        {
            ret = s.substr(palindromeStart, palindromeEnd - palindromeStart + 1);
            std::cout << ret << std::endl;
        }

        return ret;
    }
};

int main() {
    const std::string input = "ababd";
    Solution solution;
    const std::string result = solution.longestPalindrome(input);
    std::cout << result << std::endl;
    return 0;
}

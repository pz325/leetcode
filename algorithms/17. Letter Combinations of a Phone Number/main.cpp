/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include <vector>
#include <string>
#include <iostream>



void printV(const std::vector<std::string>& v)
{
    for (auto& s: v)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

class Solution
{
  public:
    std::vector<std::string> letterCombinations(const std::string& digits)
    {
        std::vector<std::string> ret;

        if (digits.empty())
        {
            return ret;
        }

        std::vector<int> d;
        for (char c: digits)
        {
            d.push_back(c - '0');
        }

        permutation("", d, digitLetters_, 0, ret);

        return ret;
    }

    private:
        void permutation(const std::string& permString, const std::vector<int>& digits, std::vector<std::vector<char>>& digitLetters, int currentIndex, std::vector<std::string>& perms)
        {
            const auto &chars = digitLetters[digits[currentIndex]];
            for (char c: chars)
            {
                std::string tmp(permString);
                tmp.push_back(c);
                if (currentIndex < digits.size() - 1)
                {
                    permutation(tmp, digits, digitLetters, currentIndex+1, perms);
                }
                else
                {
                    perms.push_back(tmp);
                }
            }
        }

        std::vector<std::vector<char>> digitLetters_ = {
            {' '},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };
};

int main()
{
    const std::string input = "234";
    Solution solution;
    auto ret = solution.letterCombinations(input);
    printV(ret);
}

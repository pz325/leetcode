/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <string>
#include <iostream>
#include <map>
#include <stack>


class Solution
{
  public:
    bool isValid(const std::string& s)
    {
        std::stack<int> bracketOrders;

        for (char c: s)
        {
            if (isOpenBracket(c))
            {
                bracketOrders.push(bracketValues_[c]);
            }
            else
            {
                if (bracketOrders.empty())
                {
                    return false;
                }
                
                const int x = bracketOrders.top();
                if (0 != x + bracketValues_[c])
                {
                    return false;
                }
                else
                {
                    bracketOrders.pop();
                }
            }
        }

        return bracketOrders.empty();
    }

    private:
    bool isOpenBracket(char c)
    {
        return (c == '(' || c == '{' || c == '[');
    }

    std::map<char, int> bracketValues_ = {
        {'(', -1},
        {')', 1},
        {'[', -2},
        {']', 2},
        {'{', -3},
        {'}', 3}
    };

};


int main()
{
    const std::string input = "]";
    Solution solution;
    auto ret = solution.isValid(input);
    std::cout << ret << std::endl;
}

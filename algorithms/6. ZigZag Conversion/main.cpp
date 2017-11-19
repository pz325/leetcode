/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>
#include <iostream>
#include <sstream>


class Solution
{
  public:
    std::string convert(const std::string& s, int numRows)
    {
        if (s.empty()) {
            return "";
        }

        if (s.size() == 1 || numRows == 1) {
            return s;
        }

        std::stringstream ss;
        for (int row = 0; row <numRows; ++row) {
            int index = row;
            ss << s[index];
            while (true) {
                if (row != numRows - 1) {
                    // zigzag down then up
                    index += 2 * (numRows - row - 1);
                    if (index >= s.size())
                    {
                        break;
                    }
                    else
                    {
                        ss << s[index];
                    }
                }

                if (row != 0) {
                    // zigzag up then down
                    index += 2 * row;
                    if (index >= s.size())
                    {
                        break;
                    }
                    else
                    {
                        ss << s[index];
                    }
                }
            }
            std::cout << "row: " << row << " output: " << ss.str() << std::endl;
        }

        return ss.str();
    }
};

int main() {
    const std::string text = "AB";
    const int numRows = 1;

    Solution solution;
    const std::string result = solution.convert(text, numRows);

    std::cout << result << std::endl;
}
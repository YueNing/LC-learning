/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<string> Roman {"M", "CM", "D", "CD", "C", \
        "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> Int{1000, 900, 500, 400, 100, 90, 50, \
        40, 10, 9, 5, 4, 1};
        int size = Int.size();
        string res;
        int start = 0;
        while (num > 0) {
            while (num >= Int[start]) {
                num -= Int[start];
                res += Roman[start];
            }
            start++;
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> RomanToInt{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int size = s.size();
        int res = 0;
        for (int i = 0; i < size; i++) {
            if (RomanToInt[s[i]] < RomanToInt[s[i + 1]]) {
                res += RomanToInt[s[i + 1]] - RomanToInt[s[i]];
                i++;
            }
            else {
                res += RomanToInt[s[i]];
            }
        }
        return res;
    }
};
// @lc code=end


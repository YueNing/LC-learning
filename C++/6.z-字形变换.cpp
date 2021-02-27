/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        int rows = min(numRows, size);
        if (rows == 1) {
            return s;
        }
        vector<string> tmp(rows);
        int flag = -1;
        int curRow = 0;
        for (auto c : s) {
            tmp[curRow] += c;
            if (curRow == 0 || curRow == rows - 1) {
                flag *= -1;
            }
            curRow += flag;
        }
        string res;
        for (auto str: tmp) {
            res += str;
        }
        return res;
    }
};
// @lc code=end


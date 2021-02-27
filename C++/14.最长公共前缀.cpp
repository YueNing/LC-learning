/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sizeOfStrs = strs.size();
        if (sizeOfStrs == 1) {
            return strs[0];
        }
        int size = INT_MAX;
        string res;
        for (string str : strs) {
            int tmp = str.size();
            size = min(size, tmp);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < sizeOfStrs - 1; j++) {
                if (strs[j][i] != strs[j + 1][i]) {
                    return res;
                }
                if (j == sizeOfStrs - 2) {
                    res += strs[j][i];
                }
            }
        }
        return res;
    }
};
// @lc code=end


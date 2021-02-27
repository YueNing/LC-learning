/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    res = max(i - stk.top(), res);
                }
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        backtracking(res, cur, 0, 0, n);
        return res;
    }
    void backtracking(vector<string>& res, string& cur, int leftParenthesis, int rightParenthesis, int max) {
        if (cur.size() == 2* max) {
            res.push_back(cur);
            return;
        }
        if (leftParenthesis < max) {
            cur.push_back('(');
            backtracking(res, cur, leftParenthesis + 1, rightParenthesis, max);
            cur.pop_back();
        }
        if (rightParenthesis < leftParenthesis) {
            cur.push_back(')');
            backtracking(res, cur, leftParenthesis, rightParenthesis + 1, max);
            cur.pop_back();
        }
    }
};
// @lc code=end


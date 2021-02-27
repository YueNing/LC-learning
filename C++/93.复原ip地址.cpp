/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int index = 0;
        string cur;
        int count = 0;
        string curRes;
        vector<string> res;
        if (s.size() == 0) {
            return res;
        }
        backtracking(s, index, cur, count, curRes, res);
        for (int i = 0; i < res.size(); i++){
            res[i].pop_back();
        }
        return res;
    }
    void backtracking(string& s, int index, string cur, int count, string& curRes, vector<string>& res) {
        cur += s[index];
        int value = stoi(cur);
        if (value > 255) {
            return;
        }
        string tmp = cur;
        string tmpRes = curRes;
        curRes += cur;
        curRes += '.';
        if (count > 3) {
            return;
        }
        if (index == s.size() - 1) {
            if (count == 3) {
                res.push_back(curRes);
                return;
            }
            else {
                return;
            }
        }
        cur.clear();
        backtracking(s, index + 1, cur, count + 1, curRes, res);
        curRes = tmpRes;
        cur = tmp;
        if (cur[0] != '0') {
            backtracking(s, index + 1, cur, count, curRes, res);
        }
    }
};
// @lc code=end


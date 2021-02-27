/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<vector<string>> res;
        vector<string> curRes;
        int cur = 0;
        backtracking(n, cur, visited, curRes, res);
        return res;
    }
    void backtracking(int n, int cur, vector<vector<int>>& visited,vector<string>& curRes, vector<vector<string>>& res) {
        if (curRes.size() == n) {
            res.push_back(curRes);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[cur][i] >= 1) {
                continue;
            }
            for (int j = cur + 1; j < n; j++) {
                visited[j][i]++;
            }
            for (int k = 1; k <= min(i , n - cur - 1); k++) {
                visited[cur + k][i - k]++;
            }
            for (int l = 1; l <= min(n - i - 1, n - cur - 1); l++) {
                visited[cur + l][i + l]++;
            }
            string tmp;
            for (int m = 0; m < n; m++) {
                m == i ? tmp += 'Q' : tmp += '.';
            }
            curRes.push_back(tmp);
            backtracking(n, cur + 1, visited, curRes, res);
            curRes.pop_back();
            for (int j = cur + 1; j < n; j++) {
                visited[j][i]--;
            }
            for (int k = 1; k <= min(i , n - cur - 1); k++) {
                visited[cur + k][i - k]--;
            }
            for (int l = 1; l <= min(n - i - 1, n - cur - 1); l++) {
                visited[cur + l][i + l]--;
            }
        }
    }
};
// @lc code=end


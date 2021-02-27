/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int res = 0;
        int cur = 0;
        backtracking(n, cur, visited, res);
        return res;
    }
    void backtracking(int n, int cur, vector<vector<int>>& visited,int& res) {
        if (cur == n) {
            res++;
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
            backtracking(n, cur + 1, visited, res);
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


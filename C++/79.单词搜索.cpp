/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        int w = board[0].size();
        vector<bool> vec(w, false);
        vector<vector<bool>> visited(h, vec);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag){
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        }
        if (k == s.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int newi;
        int newj;
        bool res;
        res = false;
        for (auto dir: directions) {
            newi = i + dir.first;
            newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag){
                        res = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return res;
    }
};
// @lc code=end


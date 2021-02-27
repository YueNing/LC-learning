/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<int>> column;
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> block;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur != '.') {
                    int value = (int)cur;
                    for (int ele : row[i]) {
                        if (cur == ele) {
                            return false;
                        }
                    }
                    for (int ele : column[j]) {
                        if (cur == ele) {
                            return false;
                        }
                    }
                    int blockIndex = (j / 3) + 3 * (i / 3);
                    for (int ele : block[blockIndex]) {
                        if (cur == ele) {
                            return false;
                        }
                    }
                    row[i].push_back(cur);
                    column[j].push_back(cur);
                    block[blockIndex].push_back(cur);
                }
            }
        }
        return true;
    }
};
// @lc code=end


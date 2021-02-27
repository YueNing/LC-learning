/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int max = n * n;
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<int> position{0, 0};
        res[position[0]][position[1]] = 1;
        int cur = 0;
        for (int i = 2; i <= max; i++) {
            int row = position[0] + direction[cur % 4][0];
            int column = position[1] + direction[cur % 4][1];
            vector<int> next{row, column};
            if (row > n - 1 || row < 0 || column > n - 1 || column < 0 || res[row][column] != 0) {
                cur++;
                row = position[0] + direction[cur % 4][0];
                column = position[1] + direction[cur % 4][1];
            }
            position[0] = row;
            position[1] = column;
            res[position[0]][position[1]] = i;
        }
        return res;
    }
};
// @lc code=end


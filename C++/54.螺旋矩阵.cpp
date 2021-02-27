/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int max = m * n;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> position{0, 0};
        res.push_back(matrix[position[0]][position[1]]);
        visited[position[0]][position[1]] = 1;
        int cur = 0;
        for (int i = 1; i < max; i++) {
            int row = position[0] + direction[cur % 4][0];
            int column = position[1] + direction[cur % 4][1];
            vector<int> next{row, column};
            if (row > m - 1 || row < 0 || column > n - 1 || column < 0 || visited[row][column] == 1) {
                cur++;
                row = position[0] + direction[cur % 4][0];
                column = position[1] + direction[cur % 4][1];
            }
            position[0] = row;
            position[1] = column;
            res.push_back(matrix[position[0]][position[1]]);
            visited[position[0]][position[1]] = 1;
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int column = 0;
        int row = 0;
        int tmp;
        int Size = size;
        while (row <= size / 2) {
            for (int i = 0; i < Size - 1; i++) {
                tmp = matrix[row + i][column];
                matrix[row + i][column] = matrix[size - column - 1][row + i];
                matrix[size - column - 1][row + i] = matrix[size - (row + i) - 1][size - column - 1];
                matrix[size - (row + i) - 1][size - column - 1] = matrix[column][size - (row + i) - 1];
                matrix[column][size - (row + i) - 1] = tmp;
            }
            row++;
            column++;
            Size -= 2;
        }
        return;
    }
};
// @lc code=end


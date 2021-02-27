/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        if (rows == 0 || columns == 0){
            return 0;
        }
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < columns; i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                res = 1;
            }
        }
        for (int j = 1; j < rows; j++) {
            if (matrix[j][0] == '1') {
                dp[j][0] = 1;
                res = 1;
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                if (matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                    res = max(res, dp[i][j]);
                }
                else {
                    continue;
                }
                    
            }
        }
        res = res * res;
        return res;
    }
};
// @lc code=end


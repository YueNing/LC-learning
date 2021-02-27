/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        stack<int> sta;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0 ? 0 : heights[i - 1][j]) + 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                while (!sta.empty() && heights[i][sta.top()] >= heights[i][j]) {
                    sta.pop();
                }
                if (sta.empty()) {
                    left[i][j] = -1;
                    sta.push(j);
                }
                else {
                    left[i][j] = sta.top();
                    sta.push(j);
                }
            }
            sta = stack<int>();
            for (int j = n - 1; j >= 0; j--) {
                while (!sta.empty() && heights[i][sta.top()] >= heights[i][j]) {
                    sta.pop();
                }
                if (sta.empty()) {
                    right[i][j] = n;
                    sta.push(j);
                }
                else {
                    right[i][j] = sta.top();
                    sta.push(j);
                }
            }
            sta = stack<int>();
            for (int j = 0; j < n; j++) {
                res = max(res, heights[i][j] * (right[i][j] - left[i][j] - 1));
            }
        }
        return res;
    }
};
// @lc code=end


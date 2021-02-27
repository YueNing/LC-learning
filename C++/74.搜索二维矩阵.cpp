/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m * n - 1;
        int low = 0;
        int i, j, mid;
        while (high >= low) {
            mid = low + (high - low) / 2;
            i = mid / n;
            j = mid % n;
            if (target > matrix[i][j]) {
                low = mid + 1;
            }
            else if (target < matrix[i][j]) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


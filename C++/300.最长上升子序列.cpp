/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int res = 1;
        vector<int> dp(size, 1);
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                res = max(dp[i], res);
            }
        }
        return res;
    }
};
// @lc code=end


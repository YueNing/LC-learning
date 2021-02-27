/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        if (size == 2) {
            return max(nums[0], nums[1]);
        }
        int res;
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int tmp;
        for (int i = 2; i < size - 1; i++) {
            tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        res = max(second, first);

        first = nums[1];
        second = max(nums[1], nums[2]);
        for (int i = 3; i < size; i++) {
            tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return max(res, max(first, second));
    }
};
// @lc code=end


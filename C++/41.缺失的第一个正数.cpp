/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] > size || nums[i] < 1) {
                nums[i] = size + 1;
            }
        }
        for (int i = 0; i < size; i++) {
            if (abs(nums[i]) <= size) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return (size + 1);
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (nums[0] > target || nums[size - 1] < target) {
            return -1;
        }
        int lowIndex = 1;
        int highIndex = size;
        while(highIndex >= lowIndex) {
            int newIndex = lowIndex + (highIndex - lowIndex) / 2;
            if (nums[newIndex - 1] > target) {
                highIndex = newIndex - 1;
            }
            else if (nums[newIndex - 1] < target) {
                lowIndex = newIndex + 1;
            }
            else {
                return newIndex - 1;
            }
        }
        return -1;
    }
};
// @lc code=end


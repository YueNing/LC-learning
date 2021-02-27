/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        if (target > nums[size - 1]) {
            return size;
        }
        while (high > low) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return low;
    }
};
// @lc code=end


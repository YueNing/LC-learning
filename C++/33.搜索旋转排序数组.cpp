/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 1) {
            if (nums[0] == target) {
                return 0;
            }
            else {
                return -1;
            }
        }
        int left = 0;
        int right = size - 1;
        if (target >= nums[0]) {
            while (right >= left) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > target || nums[mid] < nums[0]) {
                    right = mid - 1;
                }
                else if (nums[mid] < target && nums[mid] >= nums[0]) {
                    left = mid + 1;
                }
                else {
                    return mid;
                }
            }
        }
        else {
            while (right >= left) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target || nums[mid] >= nums[0]) {
                    left = mid + 1;
                }
                else if (nums[mid] > target && nums[mid] < nums[0]) {
                    right = mid - 1;
                }
                else {
                    return mid;
                }
            }
        }
        return -1;
    }
};
// @lc code=end


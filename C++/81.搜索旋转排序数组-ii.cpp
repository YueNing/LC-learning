/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 1) {
            if (nums[0] == target) {
                return true;
            }
            else {
                return false;
            }
        }
        int left = 0;
        int right = size - 1;
        int mid = left + (right - left) / 2;
        while (nums[left + 1] == nums[left] && left < size - 2) {
            left++;
        }
        while (nums[right - 1] == nums[right] && right > 1) {
            right--;
        }
        if (target == nums[0]) {
            return true;
        }
        else {
            if (target > nums[0]) {
                while (right >= left) {
                    mid = left + (right - left) / 2;
                    if (nums[mid] > target || nums[mid] < nums[0]) {
                        right = mid - 1;
                    }
                    else if (nums[mid] < target && nums[mid] >= nums[0]) {
                        left = mid + 1;
                    }
                    else {
                        return true;
                    }
                }
            }
            else {
                while (right >= left) {
                    mid = left + (right - left) / 2;
                    if (nums[mid] < target || nums[mid] >= nums[0]) {
                        left = mid + 1;
                    }
                    else if (nums[mid] > target && nums[mid] < nums[0]) {
                        right = mid - 1;
                    }
                    else if (nums[mid] == nums[0]) {
                        left++;
                    }
                    else {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid;
                while (left > 0) {
                    if (nums[left - 1] == target) {
                        left--;
                    }
                    else {
                        break;
                    }
                }
                right = mid;
                while (right < size - 1) {
                    if (nums[right + 1] == target) {
                        right++;
                    }
                    else {
                        break;
                    }
                }
                return vector<int>{left, right};
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return -1;
        }
        int sum_right = 0;
        int sum_left = 0;
        for (auto num: nums) {
            sum_right = sum_right + num;
        }
        for (int i = 0; i < size; i++) {
            sum_right = sum_right - nums[i];
            if (i != 0){
                sum_left = sum_left + nums[i - 1];
            }
            if (sum_left == sum_right) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end


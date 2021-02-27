/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }
        int flag = nums[0] - 1;
        int first = 0;
        int second = 1;
        int count = 0;
        while (second <= size - 1) {
            if (nums[first] == nums[second]) {
                second++;
            }
            else {
                for (int i = 2; i < second - first; i++) {
                    nums[first + i] = flag;
                }
                first = second;
                second += 1;
            }
        }
        for (int i = 2; i < second - first; i++) {
            nums[first + i] = flag;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] == flag) {
                count++;
            }
            else {
            nums[i - count] = nums[i];
            }
        }
        return size - count;
    }
};
// @lc code=end


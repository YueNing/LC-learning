/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first = 0;
        int second = 0;
        while (second < nums.size()) {
            if (nums[second] != val) {
                nums[first] = nums[second];
                first++;
            }
            second++;
        }
        return first;
    }
};
// @lc code=end


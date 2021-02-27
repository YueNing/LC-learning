/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int n = size - 1;
        if (n == 0) {
            return;
        }
        while (nums[n] <= nums[n - 1]) {
            n--;
            if (n == 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
        int tmp = n;
        for (int i = n; i <= size - 1; i++) {
            if (nums[i] > nums[n - 1] && nums[i] <= nums[n]) {
                tmp = i;
            }
        }
        int tmp1 = nums[n - 1];
        nums[n - 1] = nums[tmp];
        nums[tmp] = tmp1;
        reverse(nums.begin() + n, nums.end());//也可以用双指针反转
        return;
    }
};
// @lc code=end


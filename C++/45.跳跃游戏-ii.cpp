/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int pos = 0;
        while (pos < nums.size() - 1) {
            int range = 0;
            int next = 0;
            if (pos + nums[pos] >= nums.size() - 1) {
                return step + 1;
            }
            for (int i = 1; i <= nums[pos]; i++) {
                if (i + nums[pos + i] > range) {
                    range = i + nums[pos + i];
                    next = i;
                }
            }
            pos += next;
            step++;
        }
        return step;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightMax = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            if (i > rightMax){
                return false;
            }
            rightMax = max(rightMax, i + nums[i]);
            if (rightMax >= n - 1){
                return true;
            }
        }
        return true;
        // int n = nums.size();
        // int j = 1;
        // if (n == 1){
        //     return true;
        // }
        // nums.pop_back();
        // for (int i = n - 2; i >= 0; --i){
        //     if (nums[i] >= j){
        //         while (j > 1){
        //             nums.pop_back();
        //             --j;
        //             }
        //         nums.pop_back();
        //     }
        //     else {
        //         j++;
        //     }
        // }
        // if (nums.empty()){
        //     return true;
        // }
        // else {
        //     return false;
        // }
    }
};
// @lc code=end


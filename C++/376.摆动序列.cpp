/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        vector<int> up(size), down(size);
        up[0] = down[0] = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(down[i - 1], up[i - 1] + 1);                
            }
            else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        return max(up[size - 1], down[size - 1]);
    }
};

// @lc code=start
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) {
//             return n;
//         }
//         int prevdiff = nums[1] - nums[0];
//         int ret = prevdiff != 0 ? 2 : 1;
//         for (int i = 2; i < n; i++) {
//             int diff = nums[i] - nums[i - 1];
//             if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
//                 ret++;
//                 prevdiff = diff;
//             }
//         }
//         return ret;
//     }
// };
// @lc code=end


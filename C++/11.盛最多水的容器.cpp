/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int highest = 0;
        int tmp = 0;
        int size = height.size();
        for (int i = 0; i < size - 1; i++) {
            if (height[i] > highest) {
                highest = height[i];
                for (int j = i + 1; j < size; j++) {
                    tmp = min(highest, height[j]) * (j - i);
                    res = max(tmp, res);
                }
            }
        }
        return res;
    }
};
// @lc code=end


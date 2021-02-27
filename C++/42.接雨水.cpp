/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size <= 2) {
            return 0;
        }
        int first = 0;
        int second = size - 1;
        int tmp = 0;
        int res = 0;
        int minHeight = 0;
        while (second > first) {
            tmp = min(height[first], height[second]);
            for (int i = first + 1; i < second; i++) {
                if (max(minHeight, height[i]) < tmp) {
                    res += tmp - max(minHeight, height[i]);
                }
            }
            minHeight = tmp;
            if (height[first] <= height[second]) {
                for (int i = first + 1; i < size; i++) {
                    if (height[i] >= height[first]) {
                        first = i;
                        break;
                    }
                }
            }
            else {
                for (int j = second - 1; j >= 0; j--) {
                    if (height[j] >= height[second]) {
                        second = j;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


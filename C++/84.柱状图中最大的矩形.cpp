/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> sta;
        vector<int> left(size), right(size);
        int res = 0;
        for (int i = 0; i < size; i ++) {
            while (!sta.empty() && heights[sta.top()] >= heights[i]) {
                sta.pop();
            }
            if (sta.empty()) {
                sta.push(i);
                left[i] = -1;
            }
            else {
                left[i] = sta.top();
                sta.push(i);
            }
        }
        sta = stack<int>();
        for (int i = size - 1; i >= 0; i--) {
            while (!sta.empty() && heights[sta.top()] >= heights[i]) {
                sta.pop();
            }
            if (sta.empty()) {
                sta.push(i);
                right[i] = size;
            }
            else {
                right[i] = sta.top();
                sta.push(i);
            }
        }
        for (int i = 0; i < size; i++) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};
// @lc code=end


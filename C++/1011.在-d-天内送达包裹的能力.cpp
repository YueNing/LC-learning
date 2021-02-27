/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int high = 0;
        int low = 0;
        for (auto& n : weights) {
            high += n;
            low = max(low, n);
        }
        while (high > low) {
            int mid = low + (high - low) / 2;
            int tmp = mid;
            int day = 1;
            for (int weight : weights) {
                tmp -= weight;
                if (tmp < 0) {
                    tmp = mid - weight;
                    day++;
                }
            } 
            if (day > D) {
                low = mid + 1;
            }
            else if (day <= D) {
                high = mid;
            }
        }
        return low;
    }
};
// @lc code=end


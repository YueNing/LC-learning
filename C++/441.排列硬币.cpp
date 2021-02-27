/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) {
            return 0;
        }
        long low = 0;
        long high = n;
        while (high >= low) {
            long mid = low + (high - low) / 2;
            long sum = (mid + 1) * mid / 2;
            if (sum > n) {
                high = mid - 1;
            }
            else if (sum < n) {
                low = mid + 1;
            }
            else if (sum == n) {
                return mid;
            }
        }
        return low - 1;
    }
};
// @lc code=end


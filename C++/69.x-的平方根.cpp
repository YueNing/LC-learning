/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            long multi = (long)mid * mid;
            long multi1 = (long)(mid + 1) * (mid + 1);
            if (multi > x) {
                high = mid - 1;
            }
            else if (multi1 < x) {
                low = mid + 1;
            }
            else if (multi1 == x) {
                return mid + 1;
            }
            else if (multi1 > x && multi <= x) {
                return mid;
            }
        }
        return 0;
    }
};
// @lc code=end


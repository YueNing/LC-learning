/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int flag = x;
        int res = 0;
        if (x == INT_MIN) {
            return 0;
        }
        if (x < 0) {
            x = -x;
        }
        while ( x > 0) {
            int tmp = x % 10;
            x = x / 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp > 7)) {
                return 0;
            }
            res = res * 10 + tmp;
        }
        return flag > 0 ? res : -res;
    }
};
// @lc code=end


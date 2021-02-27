/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
    double quickMul(double x, long n) {
        double res = 1;
        double xContribute = x;
        while (n > 0) {
            if (n % 2 == 1) {
                res *= xContribute;
            }
            xContribute *= xContribute;
            n /= 2;
        }
        return res;
    }
};
// @lc code=end


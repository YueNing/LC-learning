/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if (s[0] - '0' == 0) {
            return 0;
        }
        dp[0] = 1;
        if (n == 1) {
            return 1;
        }
        if (s[1] -'0' == 0) {
            if (s[0] - '0' >= 3 || s[0] - '0' == 0) {
                return 0;
            }
            else {
                dp[1] = 1;
            }
        }
        else if (s[0] - '0' == 1 || (s[0] - '0' == 2 && s[1] - '0' <= 6)) {
            dp[1] = 2;
        }
        else {
            dp[1] = 1;
        }
        for (int i = 2; i < n; i++) {
            if (s[i] -'0' == 0) {
                if (s[i - 1] - '0' >= 3 || s[i - 1] - '0' == 0) {
                    return 0;
                }
                else {
                    dp[i] = dp[i - 2];
                }
            }
            else if (s[i - 1] - '0' == 1 || (s[i - 1] - '0' == 2 && s[i] - '0' <= 6)) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end


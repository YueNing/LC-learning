/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int first = 0;
        int second = 0;
        if (needle.size() == 0) {
            return 0;
        }
        while (second < haystack.size()) {
            if (haystack[second] == needle[first]) {
                first++;
                second++;
                if (first == needle.size()) {
                    return second - first;
                }
            }
            else {
                second = second - first + 1;
                first = 0;
            }
        }
        return -1;
    }
};
// @lc code=end


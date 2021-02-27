/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }
        unordered_map<char, int> map;
        int start(0), end(0), length(0), result(0);
        while (end < size) {
            char tmpChar = s[end];
            if (map.count(tmpChar) && map[tmpChar] >= start) {
                start = map[tmpChar] + 1;
                length = end - start;
            }
            map[tmpChar] = end;
            length++;
            end++;
            result = max(result, length);
        }
        return result;
    }
};
// @lc code=end


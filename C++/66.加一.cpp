/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int pos = size - 1;
        digits[pos]++;
        while (digits[pos] == 10) {
            digits[pos] = 0;
            pos--;
            if (pos == -1) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            digits[pos]++;
        }
        return digits;
    }
};
// @lc code=end


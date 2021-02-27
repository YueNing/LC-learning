/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int sizeA = a.size();
        int sizeB = b.size();
        vector<int> res;
        int addSize = abs(sizeA - sizeB);
        string addZero;
        for (int i = 0; i < addSize; i++) {
            addZero += '0';
        }
        if (sizeA - sizeB >= 0) {
            b = addZero + b;
        }
        else {
            a = addZero + a;
        }
        int sizeMax = a.size();
        int carry = 0;
        for (int i = 1; i <= sizeMax; i++) {
            int tmp = carry + (a[sizeMax - i] - '0') + (b[sizeMax - i] - '0');
            carry = tmp >> 1;
            tmp = tmp & 1;
            res.push_back(tmp);
        }
        if (carry == 1) {
            res.push_back(1);
        }
        int sizeRes = res.size();
        string ans;
        for (int i = 0; i < sizeRes; i++) {
            ans += to_string(res[sizeRes - 1 - i]);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        if (size1 == 0 || size2 == 0) {
            return "0";
        }
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans;
        vector<int> res(size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = size2 - 1; j >= 0; j--) {
                int tmp = i + j + 1;
                int y = num2[j] - '0';
                res[tmp] +=  x * y;
                while (res[tmp] / 10 != 0) {
                    res[tmp - 1] += res[tmp] / 10;
                    res[tmp] = res[tmp] % 10;
                    tmp--;
                }
            }
        }
        int begin = 0;
        while (res[begin] == 0){
            begin++;
        }
        for (int i = begin; i < res.size(); i++) {
            ans += to_string(res[i]);
        }
        return ans;
    }
};
// @lc code=end


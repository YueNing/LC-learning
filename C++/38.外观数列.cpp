/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int j = n - 1; j > 0; j--) {
            int size = s.size();
            string res;
            for (int i = 0; i < size; i++) {
                int count = 1;
                // if (i == size - 1) {
                //     string tmp = to_string(count) + s[i];
                //     res += tmp;
                // }
                // else {
                    while (s[i] == s[i + 1]) {
                        // if (i == size - 2) {
                        //     count++;
                        //     i++;
                        //     break;
                        // }
                        // else {
                            count++;
                            i++;
                        // }
                    }
                    string tmp = to_string(count) + s[i];
                    res += tmp;
                // }
            }
            s = res;
        }
        return s;
    }
};
// @lc code=end


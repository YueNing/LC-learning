/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        int N = n;
        vector<int> pos(n, 1);
        vector<int> cur(n, 1);
        for (int j = 1; j < n; j++) {
            cur[j] = j + 1;
        }
        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i - 1] * i;
        }
        string res;
        int index = n - 1;
        k--;
        while (index >= 0) {
            int tmp = k / pos[index];
            res += to_string(cur[tmp]);
            cur.erase(cur.begin() + tmp);
            k = k % pos[index];
            index--;
        }
        return res;
    }
};
// @lc code=end


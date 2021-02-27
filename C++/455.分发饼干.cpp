/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int cookie = 0;
        int n = g.size();
        int m = s.size();
        for (int i = res; i < min(n, m); ++i){
            int need = g[i];
            if (need > s[m-1]){
                return res;
            }
            for (int i = cookie; i < m; ++i){
                if (need <= s[i]){
                    res += 1;
                    cookie = i+1;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end


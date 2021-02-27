/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = strs.size();
        unordered_map<string, vector<string>> res_temp;
        for (int i = 0; i < n; ++i){
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            res_temp[strs[i]].push_back(tmp);
        }
        for (auto j = res_temp.begin(); j != res_temp.end(); ++j){
            res.push_back(j->second);
        }
        return res;
    }
};
// @lc code=end


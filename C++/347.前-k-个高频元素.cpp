/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i : nums) map[i] ++;
        vector<pair<int,int>> res;
        for(auto it : map) res.push_back(make_pair(it.second, it.first));
        sort(res.begin(), res.end());
        for(int i = 1; i <= k; i ++) nums.push_back(res[res.size() - i].second);
        return vector<int>(nums.end() - k, nums.end());
    }
};
// @lc code=end


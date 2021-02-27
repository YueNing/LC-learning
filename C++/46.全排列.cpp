/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(nums, res, cur);
        return res;
    }
    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur) {
        if (nums.size() == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            backtracking(nums, res, cur);
            nums.insert(nums.begin() + i, cur.back());
            cur.pop_back();
        }
    }
};
// @lc code=end


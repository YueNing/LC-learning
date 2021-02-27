/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            backtracking(nums, res, cur);
            nums.insert(nums.begin() + i, cur.back());
            cur.pop_back();
        }
    }
};
// @lc code=end


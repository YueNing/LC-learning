/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++) {
            backtracking(0, nums, i);
        }
        return res;
    }
    void backtracking(int cur, vector<int>& nums, int curSize) {
        if (curSize == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            if (i > cur && nums[i] == nums[i - 1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            backtracking(i + 1, nums, curSize + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end


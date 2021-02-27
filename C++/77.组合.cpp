/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    int max;
    vector<vector<int>> combine(int n, int k) {
        max = k;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(nums, 0, cur, res);
        return res;
    }
    void backtracking(vector<int> &nums, int index, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == max) {
            res.push_back(cur);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
                cur.push_back(nums[i]);
                backtracking(nums, i + 1, cur, res);
                cur.pop_back();
        }
    }
};
// @lc code=end


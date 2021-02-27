/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(candidates, res, cur, 0, 0, target);
        return res;
    }
    void backtracking(vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur, int index, int sum, int target) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        else {
            cur.push_back(candidates[index]);
            backtracking(candidates, res, cur, index, sum + candidates[index], target);
            cur.pop_back();
            while (index < candidates.size() - 1) {
                index++;
                cur.push_back(candidates[index]);
                backtracking(candidates, res, cur, index, sum + candidates[index], target);
                cur.pop_back();
            }
        }
    }
};
// @lc code=end


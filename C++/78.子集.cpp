/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
// @lc code=end
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i <= size; i++) {
            backtracking(nums, i, 0);
        }
        return res;
    }
    void backtracking(vector<int>& nums, int size, int cur) {
        if (tmp.size() == size) {
            res.push_back(tmp);
            return;
        }
        for (int i = cur; i < nums.size(); i++) {
            tmp.push_back(nums[cur]);
            backtracking(nums, size, cur + 1);
            tmp.pop_back();
            cur++;
        }
    }
};

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.push_back(candidates[i]);
            backtracking(candidates, res, cur, i + 1, sum + candidates[i], target);
            cur.pop_back();                
        } 
    }
};
// @lc code=end
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(candidates, res, cur, -1, 0, target);
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
            index++;            
            while (index <= candidates.size() - 1) {
                cur.push_back(candidates[index]);
                backtracking(candidates, res, cur, index, sum + candidates[index], target);
                cur.pop_back();
                while (index < candidates.size() - 1) {
                    if (candidates[index] == candidates[index + 1]) {
                        index++;
                    }
                    else {
                        break;
                    }
                }
                if (index ==  candidates.size() - 1) {
                    return;
                }
                index++;
            }
        }
    }
};

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        if (n == 0){
            return res;
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n - 1; ++i){
            if (intervals[i][1] < intervals[i+1][0]){
                res.push_back(intervals[i]);
            }
            else if (intervals[i][1] >= intervals[i+1][0] &&\
             intervals[i][1] <= intervals[i+1][1]){
                intervals[i + 1][0] = intervals[i][0];
            }
            else {
                intervals[i + 1] = intervals[i];
            }
        }
        res.push_back(intervals[n - 1]);
        return res;
    }
};
// @lc code=end


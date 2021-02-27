/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        bool flag = true;
        vector<vector<int>> res;
        for (int i = 0; i < size; i++) {
            if (flag) {
                if (intervals[i][1] < newInterval[0]) {
                    res.push_back(intervals[i]);
                }
                else if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) {
                    if (intervals[i][1] < newInterval[1]) {
                        newInterval[0] = intervals[i][0];
                    }
                    else {
                        res.push_back(intervals[i]);
                        flag = false;
                    }
                }
                else if (intervals[i][0] > newInterval[0] && intervals[i][0] <= newInterval[1]) {
                    if (intervals[i][1] < newInterval[1]) {
                        continue;
                    }
                    else {
                        res.push_back({newInterval[0], intervals[i][1]});
                        flag = false;
                    }
                }
                else if (intervals[i][0] > newInterval[1]) {
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                    flag = false;
                }
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        if (flag) {
            res.push_back(newInterval);
        }
        return res;
    }
};
// @lc code=end


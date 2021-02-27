/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> lhs, vector<int> rhs) {
            return (lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0]);
        });
        vector<vector<int>> res;
        // vector<int> last(people[0]);
        // res.push_back(last);
        for (int i = 0; i < people.size(); ++i){
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};
// @lc code=end


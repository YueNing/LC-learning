/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int current_tank = 0;
        int total_tank = 0;
        int start_station = 0;

        for (int i = 0; i < n; ++i)
        {
            total_tank += gas[i] - cost[i];
            current_tank += gas[i] - cost[i];
            if (current_tank < 0){
                current_tank = 0;
                start_station = i +1;
            }
        }
        return total_tank >= 0 ? start_station : -1;
    }
};
// @lc code=end


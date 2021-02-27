/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0;
        int size = grumpy.size();
        int max_saved_customers = 0;
        int saved_customers = 0;
        vector<int> unSatisfied(size, 0);
        for (int i = 0; i < size; ++i){
            unSatisfied[i] = customers[i] * grumpy[i];
            res += customers[i]*(1 - grumpy[i]);
            saved_customers += unSatisfied[i];
            if (i > X - 2){
                max_saved_customers = max(max_saved_customers, saved_customers);
                saved_customers -= unSatisfied[i - X + 1];
            }
        }
        return res + max_saved_customers;
    }
};
// @lc code=end


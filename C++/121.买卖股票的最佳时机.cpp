/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9;
        int maxProf = 0;
        for (int price: prices){
            minPrice = min(minPrice, price);
            maxProf = max(maxProf, price - minPrice);
        }
        return maxProf;
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int res = 0;
//         for (int i = 0; i < n; ++i){
//             for (int j = i + 1; j < n; ++j){  
//                 res = max(res, prices[j] - prices[i]);
//             }
//         }
//         return res;
//     }
// };
// @lc code=end


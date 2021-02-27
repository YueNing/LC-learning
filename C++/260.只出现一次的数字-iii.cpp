/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        for (auto num: nums){
            auto index = find(res.begin(), res.end(), num);
            if (index != res.end()){
                res.erase(index, index + 1);
            }
            else
                res.push_back(num);
        }
        return res;
    }
};
// @lc code=end


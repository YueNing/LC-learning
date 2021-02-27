/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = INT_MIN;
        vector<int>::iterator i = nums.begin();
        while (i != nums.end()) {
            if (*i == cur) {
                nums.erase(i);
            }
            else {
                cur = *i;
                i++;
            }
        }
        return (nums.end() - nums.begin());
    }
};
// @lc code=end


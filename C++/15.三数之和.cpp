/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        if (size < 3){
            return res;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++){
            if (nums[i] > 0){
                return res;
            }
            if (i > 0 && nums[i] == nums[i-1])  continue;
            int j = i + 1;
            int k = size - 1;
            while (j < k){
                if (nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else {
                    vector<int> tmp{nums[i], nums[j], nums[k]};
                    res.push_back(tmp);
                    while ((nums[j+1] == nums[j]) && (j < k) && (j < size - 2)){
                        j++;
                    }
                    while ((nums[k-1] == nums[k]) && (j < k)){
                        k--;
                    }
                    j++;
                    k--;
                }
            }          
        }
        return res;
    }
};
// @lc code=end


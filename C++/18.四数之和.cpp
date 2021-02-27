/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int k, l, sum;
        vector<vector<int>> res;
        for (int i = 0; i < size - 3; i ++) {
            for (int j = i + 1; j < size - 2; j++) {
                k = j + 1;
                l = size - 1;                
                while (l > k && l <= size - 1){
                    sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        while (nums[k + 1] == nums[k] && k < size - 2) {
                            k++;
                        }
                        k++;
                    }
                    else if (sum > target) {
                        while (nums[l - 1] == nums[l] && l > 1) {
                            l--;
                        }
                        l--;
                    }
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (nums[k + 1] == nums[k]) {
                            k++;
                            if (k == size - 1) {
                                break;
                            }
                        }
                        k++; 
                        while (nums[l - 1] == nums[l]) {
                            l--;
                            if (l == 0) {
                                break;
                            }
                        }
                        l--;                       
                    }
                }
                while (nums[j + 1] == nums[j]) {
                    j++;
                    if (j == size - 1) {
                        break;
                    }
                }
            }
            while (nums[i + 1] == nums[i] && i < size - 1){
                i++;
                if (i == size - 1) {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end


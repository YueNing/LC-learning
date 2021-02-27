/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 3){
            return nums[0] * nums[1] * nums[2];
        }
        vector<int> set1;
        vector<int> set2;
        bool exist0 = false;
        //int res;
        for (int i = 0; i < size; i++){
            if (nums[i] < 0){
                set1.push_back(nums[i]);
            }
            else if (nums[i] != 0){
                set2.push_back(nums[i]);
            }
            else {
                exist0 = true;
            }
        }
        sort(set1.begin(), set1.end());
        sort(set2.begin(), set2.end());
        int size1 = set1.size();
        int size2 = set2.size();
        if (size2 == 0){
            if (exist0){
                return 0;
            }
            else{
                return set1[size1 - 1] * set1[size1 - 2] * set1[size1 - 3];
            }
        }
        else if (size2 <= 2 && size1 <2){
            return 0;
        }
        else if (size2 <= 2 && size1 >=2){
            return set1[0] * set1[1] * set2[size2 - 1];
        }
        else if (size1 <= 2){
            return set2[size2 - 1]*set2[size2 - 2]*set2[size2 - 3];
        }
        else{
            return max(set2[size2 - 1]*set2[size2 - 2]*set2[size2 - 3], set1[0] * set1[1] * set2[size2 - 1]);
        }
    }
};
// @lc code=end


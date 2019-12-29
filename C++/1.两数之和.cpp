/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 无序hash散列表, 空间换时间，加速搜索的速度
        unordered_map<int, int> indicies;
        for(int i=0;i<nums.size();i++){
            if (indicies.find(target-nums[i])!=indicies.end())
                return {indicies[target-nums[i]],i};
            indicies[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

// testcase
template <typename T>
int length(T& arr){
    return sizeof(arr) / sizeof(arr[0]);
}
int main(){
    int _nums[] = {1, 2 ,3 ,4};
    vector<int> nums(_nums, _nums+length(_nums));
    Solution s = Solution();
    for(auto &i:s.twoSum(nums, 7)){
        cout<<i<<endl;
    }
    return 0;
}

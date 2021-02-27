/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         map<int, int> dict;
//         for (int i = 0; i < n; ++i){
//                 if (dict.count(nums[i])){
//                     dict[nums[i]] += 1;
//                 }
//                 else{
//                     dict[nums[i]] = 1;
//                 }                 
//         }
//         for (map<int, int>::iterator i = dict.begin(); i != dict.end(); ++i){
//             if (i->second > n/2){
//                 return i->first;
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};
// @lc code=end


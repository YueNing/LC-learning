/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res;
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         vector<int>::iterator i = nums1.begin(), j = nums2.begin();
//         while (i !=nums1.end() && j != nums2.end()){
//             if (*i == *j){
//                 res.push_back(*i);
//                 i++;
//                 j++;
//             }
//             else if (*i < *j){
//                 i++;
//             }
//             else if (*i > *j){
//                 j++;
//             }            
//         }
//         return res;
//     }
// };
    class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            unordered_map<int, int> nums1_map;
            for (int num: nums1){
                nums1_map[num]++;
            }
            for (int num: nums2){
                if(nums1_map.count(num) && nums1_map[num] > 0){
                    res.push_back(num);
                    nums1_map[num]--;
                }
            }
            return res;
    }
};
// @lc code=end


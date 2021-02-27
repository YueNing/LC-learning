/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
  public:
  /*
  荷兰三色旗问题解
  */
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int i = 0;
//         int j = 0;
//         for (int k = 0; k < n; ++k){
//             if (nums[k - j] == 0){
//                 nums.erase(nums.begin() + k - j);
//                 nums.insert(nums.begin(), (int)0);
//                 i++;
//             }
//             if (nums[k - j] == 1){
//                 nums.erase(nums.begin() + k - j);
//                 nums.insert(nums.begin() + i, (int)1);                
//             }
//             if (nums[k - j] == 2){
//                 nums.erase(nums.begin() + k - j);
//                 nums.insert(nums.end(), (int)2);
//                 j++;
//             }
//         }
//     }
// };
// @lc code=end


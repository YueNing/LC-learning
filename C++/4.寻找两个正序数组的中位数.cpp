/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        if (size % 2 == 1) {
            return getKthElement(nums1, nums2, size / 2 + 1);
        }
        else {
            return (getKthElement(nums1, nums2, size / 2) + getKthElement(nums1, nums2, size / 2 + 1)) / 2.0;
        }

    }
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int K) {
        int size1 = nums1.size();
        int size2 = nums2.size(); 
        int index1 = 0;
        int index2 = 0;
        int tmpK = K;
        while (true) {
            if (index1 == size1) {
                return nums2[tmpK - size1 - 1];
            }
            if (index2 == size2) {
                return nums1[tmpK - size2 - 1];
            }
            if (K == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            int newIndex1 = min(index1 + K / 2, size1);
            int newIndex2 = min(index2 + K / 2, size2);
            if (nums1[newIndex1 - 1] <= nums2[newIndex2 - 1]) {
                K -= newIndex1 - index1;
                index1 = newIndex1;
            }
            else {
                K -= newIndex2 - index2;
                index2 = newIndex2;                
            }
        }
    }
};
// @lc code=end


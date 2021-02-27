/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n + m == m) {
            return;
        }
        if (m + n == n) {
            nums1 = nums2;
            return;
        }
        int first = m - 1;
        int second = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (nums2[second] > nums1[first]) {
                nums1[i] = nums2[second];
                if (second == 0) {
                    break;
                }
                second--;
            }
            else {
                nums1[i] = nums1[first];
                if (first == 0) {
                    for (int j = 0; j <= i - 1; j++) {
                        nums1[j] = nums2[j];
                    }
                }
                else {
                    first--;
                }
            }
        }
        return;
    }
};
// @lc code=end


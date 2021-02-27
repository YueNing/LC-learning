/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int right = size - 1;
        int left = 0;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (mid == 0) {
                return 1;
            }
            else if (arr[mid - 1] < arr[mid] && arr[mid + 1] > arr[mid]) {
                left = mid + 1;
            }
            else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end


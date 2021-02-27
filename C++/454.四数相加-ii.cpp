/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size();
        if (size == 0) {
            return 0;
        }
        map<int, int> map1;
        map<int, int> map2;
        int res = 0;
        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j++) {
                map1[A[i] + B[j]]++;
            }
        }
        for (int k = 0; k < size; k ++) {
            for (int l = 0; l < size; l++) {
                map2[- C[k] - D[l]]++;
            }
        }
        for (auto i : map1) {
            if (i.first < map2.begin()->first) {
                continue;
            }
            if (i.first > (--map2.end())->first) {
                return res;
            }
            else {
                if (map2.find(i.first) != map2.end()) {
                    res += map2.find(i.first)->second * i.second;
                }
            }
        }
        return res;
    }
};
// @lc code=end


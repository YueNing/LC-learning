/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> generateTrees(n + 1, 0);
        generateTrees[0] = 1;
        generateTrees[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++){
                generateTrees[i] += generateTrees[j - 1] * generateTrees[i - j];
            }
        }
        return generateTrees[n];
    }
};
// @lc code=end


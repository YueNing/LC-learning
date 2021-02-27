/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode *> allTrees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            for (auto& left : leftTrees) {
                for (auto& right : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
};
// @lc code=end


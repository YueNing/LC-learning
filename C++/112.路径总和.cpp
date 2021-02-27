/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end
class Solution {
public:
    bool flag = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        int cur = 0;
        helper(root, targetSum, cur);
        return flag;
    }
    void helper(TreeNode* root, int targetSum, int cur) {
        cur += root->val;
        if (!root->left && !root->right) {
            if (cur == targetSum) {
                flag = true;
            }
        }
        if (root->left) {
            helper(root->left, targetSum, cur);
        }
        if (root->right) {
            helper(root->right, targetSum, cur);
        } 
    }
};

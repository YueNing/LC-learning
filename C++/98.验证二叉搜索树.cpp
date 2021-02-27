/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        return judgement_function(root, LONG_MIN, LONG_MAX);
    }
    bool judgement_function(TreeNode* root, long long lower, long long upper){
        if (root == nullptr){
            return true;
        }
        if (root->val <= lower || root->val >= upper){
            return false;
        }
        else
            return judgement_function(root->left, lower, root->val) && judgement_function(root->right, root->val, upper);
    }
};

// @lc code=end


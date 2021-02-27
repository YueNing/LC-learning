/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, int> f, g;
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
    void dfs(TreeNode* root){
        if (!root){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(g[root->left], f[root->left]) + max(g[root->right], f[root->right]);
    }
};
// @lc code=end


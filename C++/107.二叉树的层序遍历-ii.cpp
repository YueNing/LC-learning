/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<int> tmp;
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = q.size();
            tmp.clear();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end


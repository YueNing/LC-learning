/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> nodes;
        queue<TreeNode *> nextNodes;
        vector<int> tmp;
        nextNodes.push(root);
        while (!nextNodes.empty()) {
            nodes = nextNodes;
            nextNodes = queue<TreeNode *>();
            tmp.clear();
            while (!nodes.empty()) {
                TreeNode *node = nodes.front();
                nodes.pop();
                tmp.push_back(node->val);
                if (node->left) {
                    nextNodes.push(node->left);
                }
                if (node->right) {
                    nextNodes.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> nodes;
        stack<TreeNode *> nextNodes;
        vector<int> tmp;
        nextNodes.push(root);
        bool flag = false;
        while (!nextNodes.empty()) {
            nodes = nextNodes;
            nextNodes = stack<TreeNode *>();
            tmp.clear();
            flag = !flag;
            while (!nodes.empty()) {
                TreeNode *node = nodes.top();
                nodes.pop();
                tmp.push_back(node->val);
                if (flag){
                    if (node->left) {
                        nextNodes.push(node->left);
                    }
                    if (node->right) {
                        nextNodes.push(node->right);
                    }
                }
                else {
                    if (node->right) {
                        nextNodes.push(node->right);
                    }
                    if (node->left) {
                        nextNodes.push(node->left);
                    }                    
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end


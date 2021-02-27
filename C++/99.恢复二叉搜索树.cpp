/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        vector<int> value;
        vector<TreeNode *> node;
        stack<TreeNode *> sta;
        while (root != nullptr || !sta.empty()) {
            while (root!= nullptr) {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            node.push_back(root);
            value.push_back(root->val);
            root = root->right;
        }
        int size = value.size();
        vector<int> index;
        for (int i = 0; i < size - 1; i++) {
            if (value[i] > value[i + 1]) {
                index.push_back(i);
            }
        }
        if (index.size() == 1) {
            int tmp = node[index[0]]->val;
            node[index[0]]->val = node[index[0] + 1]->val;
            node[index[0] + 1]->val = tmp;
            return;
        }
        else {
            int tmp = node[index[0]]->val;
            node[index[0]]->val = node[index[1] + 1]->val;
            node[index[1] + 1]->val = tmp;
            return;
        }
    }
};
// @lc code=end


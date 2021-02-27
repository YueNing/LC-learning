/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        return myBuildTree(inorder, postorder, 0, n - 1, n - 1);
    }
    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int pleft, int pright, int iright) {
        if (pleft > pright) {
            return nullptr;
        }
        int rootVal = postorder[pright];
        int index = map[rootVal];
        int size = iright - index;
        TreeNode *root = new TreeNode(rootVal);
        root->right = myBuildTree(inorder, postorder, pright - size, pright - 1, iright);
        root->left = myBuildTree(inorder, postorder, pleft, pright - size - 1, index - 1);
        return root;
    }
};
// @lc code=end


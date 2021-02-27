/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0);
    }
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft) {
        if (pleft > pright) {
            return nullptr;
        }
        int rootVal = preorder[pleft];
        int index = map[rootVal];
        int size = index - ileft; 
        TreeNode *root = new TreeNode(rootVal);
        root->left = myBuildTree(preorder, inorder, pleft + 1, pleft + size, ileft);
        root->right = myBuildTree(preorder, inorder, pleft + size + 1, pright, index + 1);
        return root;
    }
};
// // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
//         root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
//         // 递归地构造右子树，并连接到根节点
//         // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
//         root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
//         return root;
// @lc code=end


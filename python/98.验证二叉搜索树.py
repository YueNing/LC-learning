#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        callback = []
        traverse_binary_tree(root, callback)

        for i in range(len(callback) - 1):
            if callback[i] > callback[i+1]:
                return False  
        return True

    def traverse_binary_tree(node, callback):
        if node is None:
            return
        traverse_binary_tree(node.left, callback)
        callback.append(node.val)
        traverse_binary_tree(node.right, callback)
# @lc code=end


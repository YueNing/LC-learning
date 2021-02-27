/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        queue<TreeNode *> Q;
        queue<TreeNode *> P;
        Q.push(q);
        P.push(p);
        while (!Q.empty() && !P.empty()) {
            TreeNode *nodeQ = Q.front();
            TreeNode *nodeP = P.front();
            Q.pop();
            P.pop();
            if (nodeQ->val != nodeP->val) {
                return false;
            }
            TreeNode *leftQ = nodeQ->left;
            TreeNode *rightQ = nodeQ->right;
            TreeNode *leftP = nodeP->left;
            TreeNode *rightP = nodeP->right;
            if ((!leftQ ^ !leftP) || (!rightQ ^ !rightP)) {
                return false;
            }
            if (leftQ && leftP) {
                Q.push(leftQ);
                P.push(leftP);
            }
            if (rightQ && rightP) {
                Q.push(rightQ);
                P.push(rightP);
            }
        }
        return true;
    }
};

/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len = -1;
        ListNode *tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        return buildTree(head, 0, len);
    }
    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left + 1) / 2;
        TreeNode *root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }
};
// @lc code=end
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    TreeNode* buildTree(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode *slow = left;
        ListNode *quick = left;
        while (quick->next != right && quick->next->next != right) {
            quick = quick->next->next;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = buildTree(left, slow);
        root->right = buildTree(slow->next, right);
        return root;
    }
};
/////////
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);
    }
    TreeNode* buildTree(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *quick = head;
        ListNode *prev = head;
        while (quick != nullptr && quick->next != nullptr) {
            quick = quick->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (prev->next == nullptr) {
            return root;
        }
        prev->next = nullptr;
        root->left = buildTree(head);
        root->right = buildTree(slow->next);
        return root;
    }
};
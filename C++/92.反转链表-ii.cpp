/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = right - left;
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *prev = dummyNode;
        ListNode *tmp;
        for (int i = 1; i < left; i++) {
            dummyNode = dummyNode->next;
        }
        ListNode *first = dummyNode->next;
        ListNode *prevFirst = first;
        ListNode *second = first->next;
        for (int i = 0; i < n; i++) {
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        dummyNode->next = first;
        prevFirst->next = second;
        return prev->next;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyNode = ListNode(0, head);
        ListNode *first(head);
        ListNode *second(&dummyNode);
        for (int i = 0; i < n - 1; i++) {
            first = first->next;
        }
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummyNode.next;
    }
};
// @lc code=end


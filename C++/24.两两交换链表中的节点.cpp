/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *prev = dummyHead;
        while (dummyHead->next != nullptr && dummyHead->next->next != nullptr) {
            ListNode *first = dummyHead->next;
            ListNode *second = dummyHead->next->next;
            dummyHead->next = second;
            first->next = second->next;
            second->next = first;
            dummyHead = first;
        }
        return prev->next;
    }
};
// @lc code=end


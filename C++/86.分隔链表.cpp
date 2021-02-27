/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyNode = new ListNode(0);
        ListNode *midNode = new ListNode(0);
        ListNode *prev1 = midNode;
        ListNode *prev = dummyNode;
        while (head != nullptr) {
            if (head->val < x) {
                dummyNode->next = head;
                dummyNode = dummyNode->next;
            }
            else {
                midNode->next = head;
                midNode = midNode->next;
            }
            head = head->next;
        }
        midNode->next = nullptr;
        dummyNode->next = prev1->next;
        return prev->next;
    }
};
// @lc code=end


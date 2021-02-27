/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {     
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *tail = dummyNode;
        ListNode *prev = dummyNode;
        ListNode *tmp = dummyNode;
        while (true) {
            for (int i = 0; i < k; i++) {
                if (tail->next == nullptr) {
                    return tmp->next;
                }
                tail = tail->next;
            }
            ListNode *nst = tail->next;
            tail->next = nullptr;
            while (head != nullptr) {
                ListNode *nxt = head->next;
                head->next = prev;
                prev = head;
                head = nxt;
            }
            tail = dummyNode->next;
            dummyNode->next->next = nst;
            dummyNode->next = prev;
            prev = tail;
            head = nst;
            dummyNode = prev;
        }
        return tmp->next;
    }
};
// @lc code=end


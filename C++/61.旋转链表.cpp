/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *tail = head;
        int count = 0;
        while (tail->next != nullptr) {
            tail = tail->next;
            count++;
        }
        tail->next = head;
        int tmp = count - k % (count + 1);
        ListNode *breakNode = head;
        for (int i = 0; i < tmp; i++) {
            breakNode = breakNode->next;
        }
        head = breakNode->next;
        breakNode->next = nullptr;
        return head;
    }
};
// @lc code=end


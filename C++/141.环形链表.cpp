/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            if (head->next == head) {
                return true;
            }
            else
                return false;
        }
        ListNode *quick_pointer = head->next;
        ListNode *slow_pointer = head;
        while (quick_pointer !=slow_pointer) {
            if (quick_pointer->next == nullptr || quick_pointer->next->next == nullptr) {
                return false;
            }
            quick_pointer = quick_pointer->next->next;
            slow_pointer = slow_pointer->next;
        }
        return true;
    }
};
// @lc code=end


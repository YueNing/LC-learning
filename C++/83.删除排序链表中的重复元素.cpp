/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            while (tmp->next != nullptr && tmp->val == tmp->next->val) {
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            prev = prev->next;
            tmp = prev;
        }
        return head;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        if (head == nullptr) {
            return head;
        }
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *prev = dummyNode;
        bool flag = false;
        int count = 1;
        while (second != nullptr) {
            if (first->val == second->val) {
                count++;
            }
            else if (count == 1 && first->val != second->val) {
                dummyNode->next = first;
                dummyNode = dummyNode->next;
                flag = true;
                first = first->next;
            }
            else {
                first = second;
                count = 1;
            }
            second = second->next;
        }
        if (count == 1) {
            dummyNode->next = first;
            flag = true;
        }
        else {
            dummyNode->next = nullptr;
        }
        if (!flag) {
            return nullptr;
        }
        return prev->next;
    }
};
// @lc code=end


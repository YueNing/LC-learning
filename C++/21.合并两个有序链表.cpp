/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyNode = new ListNode(0, nullptr);
        ListNode *prev = dummyNode;
        while (l2 != nullptr && l1 != nullptr) {
            if (l2->val <= l1->val) {
                dummyNode->next = l2;
                l2 = l2->next;
            }
            else {
                dummyNode->next = l1;
                l1 = l1->next;
            }
            dummyNode = dummyNode->next;
        }
        dummyNode->next = l1 == nullptr ? l2 : l1;
        return prev->next;
    }
};
// @lc code=end


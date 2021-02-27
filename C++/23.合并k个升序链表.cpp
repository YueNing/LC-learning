/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        else {
            int mid = l + (r - l) / 2;
            return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
        }
    }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || !b) {
            return a ? a : b;
        }
        ListNode *dummyNode = new ListNode(0, nullptr);;
        ListNode *prev = dummyNode;
        while (a && b) {
            if (a->val <= b->val) {
                dummyNode->next = a;
                a = a->next;
            }
            else {
                dummyNode->next = b;
                b = b->next;
            }
            dummyNode = dummyNode->next;
        }
        dummyNode->next = a == nullptr ? b : a;
        return prev->next;
    }
};
// @lc code=end


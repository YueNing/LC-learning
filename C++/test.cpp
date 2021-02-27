#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <typeinfo>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = -1;
        TreeNode *tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        return buildTree(head, 0, len);
    }
    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left + 1) / 2;
        TreeNode *root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }
};

int main(){
    Solution s;
    vector<vector<char>> nums{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    ListNode *a = new ListNode(9, nullptr);
    ListNode *b = new ListNode(5, a);
    ListNode *c = new ListNode(0, b);
    ListNode *e = new ListNode(-3, c);
    ListNode *f = new ListNode(-10, e);

    ListNode *g = new ListNode(1, f);
    ListNode *h = new ListNode(1, g);
    TreeNode *A = new TreeNode(2);
    TreeNode *B = new TreeNode(3, nullptr, A);
    TreeNode *C = new TreeNode(1, B, nullptr);
    vector<int> postorder{9, 15, 7, 20, 3};
    vector<int> inorder{-10,-3,0,5,9};
    s.sortedListToBST(f);
    //vector<string> res = s.generateParenthesis(3);

    // ListNode *first = new ListNode(1);
    // ListNode *second = new ListNode(2, first);
    // ListNode *dummy = new ListNode(3);
    // dummy->next = second;
    // second = second->next;
    // cout << dummy->next;
    // delete second;
    // delete dummy->next;
    // delete first;
    // int c = 4;
    // int e = 2;
    // int *d = &e;
    // int *b = &c;
    // int *a = b;
    // b = d;
    // cout << a;
    // cout << &c;
    // cout << &e;
    getchar();
    // Solution s;
    // ListNode d(4);
    // ListNode c(3, &d);
    // ListNode b(2, &c);
    // ListNode a(1, &b);
    // //s.findMid(&a);
    // cout << a.val << a.next->val << a.next->next->val;
    // ListNode * e = &c;
    // e->next = NULL;
    // if (c.next == NULL){
    //     cout << a.val << a.next->val << a.next->next->val;
    // }
    // getchar();
}
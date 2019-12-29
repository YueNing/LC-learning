#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
    ListNode(){this->val=0;this->next=NULL;}//cout<<"default c"<<endl;}
    ListNode(int const& val){this->val=val;this->next=NULL;}//cout<<"custom c"<<endl;}
    ListNode(int const& val, ListNode* next)
    {this->val=val;this->next=next;}//cout<<"custom c"<<endl;}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        int sum;
        while (l1 || l2){
            sum = 0;
            cout<<(curr->val)<<"->";
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        if (carry > 0) 
            curr->next = new ListNode(carry);
        cout<<(curr->val)<<"->";
        return dummyHead->next;
    }
};

int main() {
    Solution s = Solution();
    //ListNode n1(0);
    ListNode m1(9);
    ListNode l1(9, &m1);
    ListNode n2(1);
    ListNode m2(0, &n2);
    ListNode l2(1, &m2);
    s.addTwoNumbers(&l1, &l2);
    return 0;
}
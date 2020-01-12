#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(){this->val=0;this->left=NULL;this->right=NULL;}//cout<<"default c"<<endl;}
    TreeNode(int const& val){this->val=val;this->left=NULL;this->right=NULL;}//cout<<"custom c"<<endl;}
    TreeNode(int const& val, TreeNode* left, TreeNode* right)
    {this->val=val;this->left=left;this->right=right;}//cout<<"custom c"<<endl;}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
    bool ismirror(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL&&t2==NULL)//都为空
            return true;
        if(t1==NULL||t2==NULL)//有一个为空
            return false;
        return (t1->val==t2->val)&&ismirror(t1->left,t2->right)&&ismirror(t1->right,t2->left);
    }
};

int main(){
    TreeNode f(0, NULL, NULL);
    TreeNode e(0, NULL, &f);
    TreeNode d(0, NULL, NULL);
    TreeNode c(0, &d, &e);
    TreeNode b(0, NULL, NULL);
    TreeNode a(0, &b, &c);
    Solution s;
    auto result = s.isSymmetric(&a);
    cout<< result <<" ";
}


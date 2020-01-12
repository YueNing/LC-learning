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
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        else
        {
            return 1+max(maxDepth(root->left), maxDepth(root->right));
        }                   
    }
};

int main() {
    TreeNode f(0, NULL, NULL);
    TreeNode e(0, NULL, &f);
    TreeNode d(0, NULL, NULL);
    TreeNode c(0, &d, &e);
    TreeNode b(0, NULL, NULL);
    TreeNode a(0, &b, &c);
    Solution s;
    auto result = s.maxDepth(&a);
    cout<< result <<" ";
}
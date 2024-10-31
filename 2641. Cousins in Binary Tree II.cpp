#include <iostream>
#include <algorithm>
using namespace std ;
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    TreeNode* new_root = s.replaceValueInTree(root);
    cout<<new_root->val<<endl;
    cout<<new_root->left->val<<endl;
    cout<<new_root->right->val<<endl;
    cout<<new_root->left->left->val<<endl;
    cout<<new_root->left->right->val<<endl;
    cout<<new_root->right->left->val<<endl;
    return 0;
}
// output [0,0,0,7,7,null,11]

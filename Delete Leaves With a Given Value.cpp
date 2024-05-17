/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    TreeNode* removeLeafNodes(TreeNode* ptr, int t) {
        if(ptr->left) ptr->left=removeLeafNodes(ptr->left,t);
        if(ptr->right) ptr->right=removeLeafNodes(ptr->right,t);
        if(ptr->left==NULL&&ptr->right==NULL&&ptr->val==t) return NULL;
        return ptr;
    }
};

int main(){
    Solution s ;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(NULL);
    root->left->right = new TreeNode(NULL);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    int target = 2 ;
    TreeNode* result = s.removeLeafNodes(root, target);
    cout << result -> val << endl;  
}
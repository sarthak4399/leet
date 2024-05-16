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
    bool evaluateTree(TreeNode* root) {
        if(root == NULL){
            return false;
        }
        return bfs(root);
    }
    int bfs( TreeNode* root){
        
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        int left = bfs(root->left);
        int right = bfs(root->right);
        if(root->val == 1){
            return true;
        }
        else if(root->val == 3){
            return left && right;
        }
        else if( root-> val == 2){
            // boolen or 
            return left || right;
        }
        else if (root->val == 0){
            return false;
        }
        return false;
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
    cout << s.evaluateTree(root) << endl ;
}
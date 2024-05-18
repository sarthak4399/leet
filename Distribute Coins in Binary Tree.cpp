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
#include<iostream>
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
    int needCoins(TreeNode* r, int& steps){
        if(r==nullptr) return 0;
        int c1=needCoins(r->left, steps);
        int c2=needCoins(r->right, steps);
        steps+=(abs(c1)+abs(c2));
        return c1+c2+(r->val-1);
    }

    int distributeCoins(TreeNode* root) {
        int steps=0;
        needCoins(root, steps);
        return steps;
    }
};

int main(){
    Solution s ;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    int steps = 0 ;
   cout <<  s.needCoins(root, steps) << endl;
}
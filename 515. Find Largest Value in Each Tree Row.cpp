#include <iostream>
#include <vector>
#include <climits>
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
    vector<int> largestValues(TreeNode* root) {
		vector<int> ans ;
		if(root == nullptr){
			return ans ;
		}
		vector<TreeNode*> q ;
		q.push_back(root) ;
		while(!q.empty()){
			int n = q.size() ;
			int max_val = INT_MIN ;
			for(int i = 0 ; i < n ; i++){
				TreeNode* node = q.front() ;
				q.erase(q.begin()) ;
				max_val = max(max_val,node->val) ;
				if(node->left != nullptr){
					q.push_back(node->left) ;
				}
				if(node->right != nullptr){
					q.push_back(node->right) ;
				}
			}
			ans.push_back(max_val) ;
		}
		return ans ;


    }
};

int main(){
	Solution s ;
	TreeNode* root = new TreeNode(1) ;
	root->left = new TreeNode(3) ;
	root->right = new TreeNode(2) ;
	root->left->left = new TreeNode(5) ;
	root->left->right = new TreeNode(3) ;
	root->right->right = new TreeNode(9) ;
	vector<int> ans = s.largestValues(root) ;
	for(auto i : ans){
		cout<< i << " " ;
	}
	cout<< endl ;
	return 0 ;
}
#include<iostream>
#include<vector>
using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right() {}
} TreeNode;

class Solution{
private:
	vector<int> post;
public:
	void postorder(TreeNode* root){
		if(root == NULL) return;
		postorder(root->left);
		postorder(root->right);
		//cout << root->val << endl;	
		post.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		postorder(root);
		return post;
	}
};

int main(int argc, char* argv[]){
	Solution sol;
	return 0;
}

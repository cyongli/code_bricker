/*
题意:判断一颗二叉树是否时对称的
递归解法:
 其中左子树和右子树对称的条件：
  1.两个节点值相等，或者都为空
  2.左节点的左子树和右节点的右子树对称
  3.左节点的右子树和右节点的左子树对称

非递归解法:
  用层次遍历半段每层是否是对称的
*/
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *left, TreeNode *right){
        if(left==NULL) return right==NULL;
        else if(right==NULL) return left==NULL;
        else if(left->val != right->val) return false;
        else if(!isSymmetric(left->left,right->right)) return false;
        else if(!isSymmetric(left->right,right->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return isSymmetric(root->left,root->right);
    }
};

int main(int argc, char *argv[]){
	return 0;
}

// 平衡二叉树：左右子树深度之差不大于1
// 递归计算每棵子树的深度

#include <iostream>
using namespace std;

typedef struct BiTNode{
	int val;
	BiTNode *left;
	BiTNode *right;
}BiTreeNode, *BiTree;

void createBiTree(BiTree &T){
	int c;
	cin >> c;
	if(c == -1){
		T = NULL;
	}else{
		T = new BiTreeNode;
		T->val = c;
		createBiTree(T->left);
		createBiTree(T->right);
	}
}

int depth_of_tree(BiTree root, int depth){
	if(!root){
		return 0;
	}
	if(root){
		int ldepth = depth_of_tree(root->left, depth) + 1;
		int rdepth = depth_of_tree(root->right, depth) + 1;
		depth = max(ldepth, rdepth);
	}
	return depth;
}

bool isBalanced(BiTree root){
	if(root){
		int ldepth = depth_of_tree(root->left, 0) + 1;
		int rdepth = depth_of_tree(root->right, 0) + 1;
		if(abs(ldepth - rdepth) > 1){
			return false;
		}else{
			bool l = isBalanced(root->left);
			bool r = isBalanced(root->right);
			if(!(l && r)){
				return false;
			}
		}
	}
	return true;
}


int main(){
	BiTree Tree;
	createBiTree(Tree);
	
	if(isBalanced(Tree)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	
	return 0;
}

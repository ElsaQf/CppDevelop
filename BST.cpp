// 二叉搜索树：左子树小于根节点，右子树大于根节点
// 方法：中序遍历，递增，则是二叉搜索树BST


#include <iostream>
#include <stack>
#include <queue>
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

queue<int> inOrder(BiTree T){
	stack<BiTreeNode *> s;
	queue<int> inOrderVal;
	BiTreeNode *p = T;
	while(p != NULL || !s.empty()){
		while(p != NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			inOrderVal.push(p->val);
			s.pop();
			p = p->right;
		}
	}
	return inOrderVal;
}

bool isBST(BiTree T){
	stack<BiTreeNode *> s;
	queue<int> inOrderVal;
	BiTreeNode *p = T;
	while(p != NULL || !s.empty()){
		while(p != NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			inOrderVal.push(p->val);
			s.pop();
			p = p->right;
		}
	}
	int i = inOrderVal.front();
	inOrderVal.pop();
	for(int j = inOrderVal.front(); !inOrderVal.empty(); inOrderVal.pop()){
		if(i > j){
			return false;
		}else{
			i = j;
			j = inOrderVal.front();
		}
	}
	return true;
}



int main(){
	BiTree Tree;
	createBiTree(Tree);
	queue<int> TreeVal = inOrder(Tree);
//	while(!TreeVal.empty()){
//		int i = TreeVal.front();
//		cout << i << " ";
//		TreeVal.pop();
//	}
	if(isBST(Tree)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	
	return 0;
} 

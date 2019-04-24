#include <iostream>
#include <stack>
#include <queue>
using namespace std;



typedef struct BiTNode{
	int data;
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
		T->data = c;
		createBiTree(T->left);
		createBiTree(T->right); 
	}
}

//先序遍历
//递归
void preOrder1(BiTree T){
	if(T != NULL){
		cout << T->data << " ";
		preOrder1(T->left);
		preOrder1(T->right);
	}
} 
//非递归 
void preOrder2(BiTree T){
	stack<BiTreeNode *> s;
	BiTreeNode *p = T;
	while(p != NULL || !s.empty()){
		while(p != NULL){
			cout << p->data << " ";
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}
//中序遍历
//递归 
void inOrder1(BiTree T){
	if(T != NULL){
		inOrder1(T->left);
		cout << T->data << " ";
		inOrder1(T->right);
	}
}
//非递归
void inOrder2(BiTree T){
	stack<BiTreeNode *> s;
	BiTreeNode *p = T;
	while(p != NULL || !s.empty()){
		while(p != NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->right;
		}
	}
} 

//后序遍历
//递归
void postOrder1(BiTree T){
	if(T != NULL){
		postOrder1(T->left);
		postOrder1(T->right);
		cout << T->data << " ";
	}
} 
//非递归
void postOrder2(BiTree T){
	stack<BiTreeNode *> s;
	BiTreeNode *cur;
	BiTreeNode *pre = NULL;
	s.push(T);
	while(!s.empty()){
		cur = s.top();
//		当前节点没有左右子树或者左右子树都已被访问过 
		if((cur->left == NULL && cur->right == NULL) ||
		(pre != NULL && (pre == cur->left || pre == cur->right))){
			cout << cur->data << " ";
			s.pop();
			pre = cur;
		}else{
			if(cur->right){
				s.push(cur->right);
			}
			if(cur->left){
				s.push(cur->left);
			}
		}
	}
}

//层次遍历
void levelTraverse(BiTree T){
	if(!T){
		return;
	}
	BiTree temp;
	queue<BiTreeNode *> q;
	q.push(T);
	while(!q.empty()){
		temp = q.front();
		cout << temp->data << " ";
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
		q.pop();
	}
} 

//深度遍历
void deepTraverse(BiTree T){
	if(!T){
		return;
	}
	BiTree temp;
	stack<BiTree> s;
	s.push(T);
	while(!s.empty()){
		temp = s.top();
		cout << temp->data << " ";
		s.pop();
		if(temp->right){
			s.push(temp->right);
		}
		if(temp->left){
			s.push(temp->left);
		}
	}
} 



int main(){
	BiTree Tree;
	createBiTree(Tree);
	preOrder(Tree);
	
	return 0;
}

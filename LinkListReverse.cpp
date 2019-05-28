#include <iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};

void createList(ListNode *&L){
	ListNode *end = L;
	
	int c;
	cin >> c;
	
	while(c != -1){
		ListNode *s = new ListNode;
		s->val = c;
		s->next = NULL;
		end->next = s;
		end = s;
		cin >> c;
	}
}

void printList(ListNode *L){
	ListNode *p = L->next;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
}

void reverseList(ListNode *&L){
	ListNode *p = L->next;
	ListNode *s = new ListNode;
	s->val = 0;
	s->next = NULL;
	int i = 0;
	while(p != NULL){
		L->next = p->next;
		p->next = s;
		i++;
		if(i == 1){
			p->next = NULL;
		}
		s = p;
		p = L->next;
	}
	L->next = s;
}


int main(){
	ListNode *list = new ListNode;
	list->val = 0;
	list->next = NULL;
	createList(list);
	reverseList(list);
	printList(list);
	
	return 0; 
} 

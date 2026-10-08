/*#include<iostream>
#define TRUE 1
#define FALSE 0

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;
Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = NULL;
	L->next = NULL;
	return L;
}
void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0) {
		node->next = L->next;
		node->pre = L;
		L->next = node;
	}
	else {
		node->pre = L;
		node->next = L->next;
		L->next->pre = node;
		L->next = node;
		L->data++;
	}
}
void tailInsert(Node* L, int data) {
	Node* head = L;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (head->next) {
		head = head->next;
	}
	node->next = head->next;
	head->next = node;
	node->pre = head;
	L->data++;
}
int deleteList(Node* L, int data) {
	Node* current = L->next;
	while (current) {
		if (current->data == data) {
			current->pre->next = current->next;
			current->next->pre = current->pre;
			free(current);
			return TRUE;
		}
		current = current->next;
	}
	return FALSE;
}
Node* mergeList(Node* L1, Node* L2) {
	if (L1 == NULL) {
		return L2;
	}
	if (L2 == NULL) {
		return L1;
	}
	Node* p = L1;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = L2;
	L2->pre = p;
	return L1;
}
Node* splitList(Node* L, int n) {
	if (L == NULL || n <= 0) {
		return NULL;
	}
	Node* p = L;
	int count = 1;
	while (count < n && p->next != NULL) {
		p = p->next;
		count++;
	}
	if (p == NULL) {
		return NULL;
	}
	Node* new_L = p->next;
	if (new_L != NULL) {
		new_L->pre = NULL;
	}
	p->next = NULL;
	return new_L;
}
void printList(Node* L) {
	Node* current = L->next;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
int main() {
	Node* L1 = initList();
	Node* L2 = initList();
	for (int i = 0;i < 10;i++) {
		headInsert(L1, i);
		tailInsert(L2, i);
	}
	printList(L1);
	printList(L2);
	deleteList(L1, 8);
	deleteList(L2, 1);
	printList(L1);
	printList(L2);
	Node* L = mergeList(L1, L2);
	printList(L);
	Node* new_L = splitList(L, 10);
	printList(L);
	printList(new_L);

	return 0;  
}*/
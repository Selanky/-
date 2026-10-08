/*#include<iostream>

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;
Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = L;
	L->next = L;
	return L;
}
void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (L->data == 0) {
		node->pre = L;
		node->next = L->next;
		L->next = node;
		L->pre = node;
	}
	else {
		node->next = L->next;
		node->pre = L;
		L->next->pre = node;
		L->next = node;
		L->data++;
	}
}
void tailInsert(Node* L, int data) {
	Node* head = L;
	while (head->next != L) {
		head = head->next;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->pre = head;
	node->next = L;
	L->pre = node;
	head->next = node;
	L->data++;
}
int deleteList(Node* L, int data) {
	Node* current = L->next;
	while (current != L) {
		if (current->data == data) {
			current->pre->next = current->next;
			current->next->pre = current->pre;
			free(current);
			L->data--;
			return 1;
		}
		current = current->next;
	}
	return 0;
}
Node* mergeList(Node* L1, Node* L2) {
	if (L1 == NULL) {
		return L2;
	}
	if (L2 == NULL) {
		return L1;
	}
	L1->pre->next = L2->next;
	L2->next->pre = L1->pre;
	L1->pre = L2->pre;
	L2->pre->next = L1;
	return L1;
}
Node* splitList(Node* L, int n) {
	if (L == NULL || n <= 0) {
		return NULL;
	}
	Node* p = L;
	int count = 1;
	while (count < n && p != L) {
		p = p->next;
		count++;
	}
	Node* new_L = p->next;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	p->pre = NULL;
	p->next = NULL;
	return new_L;
}
void printList(Node* L) {
	Node* current = L->next;
	while (current != L) {
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
	deleteList(L1, 9);
	deleteList(L2, 0);
	printList(L1);
	printList(L2);
	Node* L = mergeList(L1, L2);
	printList(L);
	Node* new_L = splitList(L, 10);
	printList(L);
	printList(new_L);

	return 0;
}*/
/*#include<iostream>
#define TRUE 1
#define FALSE 0

typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	return L;
}
void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}
void tailInsert(Node* L, int data) {
	Node* head = L;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	head = L->next;
	while (head->next != L) {
		head = head->next;
	}
	node->next = L;
	head->next = node;
}
int deleteList(Node* L, int data) {
	Node* head = L;
	Node* current = L->next;
	while (current != L) {
		if (current->data == data) {
			head->next = current->next;
			free(current);
			return TRUE;
		}
		head = current;
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
	Node* p1 = L1->next;
	Node* p2 = L2->next;
	p1->next = L2;
	p2->next = L1;
	return L1;
}
Node* splitList(Node* L, int n) {
	if (L == NULL || n <= 0 || L->next == L) {
		return L;
	}
	Node* p = L;
	int count = 1;
	while (count < n && p->next != L) {
		p = p->next;
	}
	Node* new_L = p->next;
	p->next = L->next;
	L->next = new_L;
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
	Node* new_L = splitList(L, 9);
	printList(L);
	printList(new_L);

	return 0;
}*/
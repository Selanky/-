/*#include<iostream>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
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
	for (int i = 0; i < L->data; i++) {
		head = head->next;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	head->next = node;
	L->data++;
}
void deleteList(Node * L, int data) {
	Node* head = L;
	Node* current = L->next;
	while (current) {
		if (current->data == data) {
			head->next = current->next;
			free(current);
			L->data--;  
			return;     
		}
		head = current;
		current = current->next;
	}
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
	if (count < n) {
		return NULL;
	}
	Node* new_L = p->next;
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
	deleteList(L1, 5);
	deleteList(L2, 4);
	printList(L1);
	printList(L2);
	Node* L = mergeList(L1, L2);
	printList(L);
	Node* new_L = splitList(L, 7);
	printList(L);
	printList(new_L);

	return 0;
}*/
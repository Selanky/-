/*#include<iostream>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* initStack() {
	Node* S = (Node*)malloc(sizeof(Node));
	S->data = 0;
	S->next = NULL;
	return S;
}
int isEmpty(Node* S) {
	if (S->data == 0 || S->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
int getTop(Node* S) {
	if (isEmpty(S)) {
		return -1;
	}
	else {
		return S->next->data;
	}
}
int pop(Node* S) {
	if (isEmpty(S)) {
		return -1;
	}
	else {
		Node* current = S->next;
		int data = current->data;
		S->next = current->next;
		free(current);
		return data;
	}
}
void push(Node* S, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = S->next;
	S->next = node;
	S->data++;
}
void printStack(Node* S) {
	Node* current = S->next;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
int main() {
	Node* S = initStack();
	for (int i = 0;i < 10;i++) {
		push(S, i);
	}
	printStack(S);
	int i = pop(S);
	std::cout << i << std::endl;
	printStack(S);

	return 0;
}*/
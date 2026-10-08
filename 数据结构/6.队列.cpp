/*#include<iostream>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* initQueue() {
	Node* Q = (Node*)malloc(sizeof(Node));
	Q->data = 0;
	Q->next = NULL;
	return Q;
}
Node* enQueue(Node* Q, int data) {
	Node* head = Q;
	Node* node = (Node*)malloc(sizeof(Node));
	for (int i = 0;i < Q->data;i++) {
		head = head->next;
	}
	node->next = head->next;
	head->next = node;
	Q->data++;
	return Q;
}
int isEmpty(Node* Q) {
	if (Q->data == 0 || Q->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
int deQueue(Node* Q) {
	if (isEmpty(Q)) {
		return -1;
	}
	else {
		Node* node = Q->next;
		int data = node->data;
		Q->next = node->next;
		free(node);
	}
	std::cout << std::endl;
}
void printQueue(Node* Q) {
	Node* current = Q->next;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
int main() {
	Node* Q = initQueue();
	for (int i = 0;i < 10;i++) {
		enQueue(Q, i);
	}
	printQueue(Q);
	int data = deQueue(Q);
	std::cout << data << std::endl;
	printQueue(Q);

	return 0;
}*/
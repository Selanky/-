/*#include<iostream>
#define MAX 15

typedef struct Queue {
	int front;
	int rear;
	int data[MAX];
}Queue;
Queue* initQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = Q->rear = 0;
	return Q;
}
int isFull(Queue* Q) {
	if ((Q->rear + 1) % MAX == Q->front) {
		return 1;
	}
	else {
		return 0;
	}
}
int enQueue(Queue* Q, int data) {
	if (isFull(Q)) {
		return 0;
	}
	else {
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % MAX;
		return 1;
	}
}
int isEmpty(Queue* Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}
int deQueue(Queue* Q) {
	if (isEmpty(Q)) {
		return -1;
	}
	else {
		int data = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAX;
		return data;
	}
}
void printQueue(Queue* Q) {
	int length=(Q->rear - Q->front + MAX) % MAX;
	int index = Q->front;
	for (int i = 0;i < length;i++) {
		std::cout << Q->data[index] << " ";
		index = (index + 1) % MAX;
	}
	std::cout << std::endl;
}
int main() {
	Queue* Q = initQueue();
	for (int i = 0;i < 10;i++) {
		enQueue(Q, i);
	}
	printQueue(Q);
	deQueue(Q);
	printQueue(Q);

	return 0;
}*/
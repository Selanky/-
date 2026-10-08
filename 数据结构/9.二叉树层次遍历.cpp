/*#include<iostream>

typedef struct Tree {
	char data;
	struct Tree* left;
	struct Tree* right;
}Tree;
typedef struct Queue {
	Tree* data;
	struct Queue* pre;
	struct Queue* next;
}Queue;
Queue* initQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->data = NULL;
	Q->pre = Q;
	Q->next = Q;
	return Q;
}
int isEmpty(Queue* Q) {
	if (Q->next == Q) {
		return 1;
	}
	else {
		return 0;
	}
}
void enQueue(Tree* data, Queue* Q) {
	Queue* node = (Queue*)malloc(sizeof(Queue));
	node->data = data;
	node->pre = Q->pre;
	node->next = Q;
	Q->pre->next = node;
	Q->pre = node;
}
Queue* deQueue(Queue* Q) {
	if (isEmpty(Q)) {
		return NULL;
	}
	else {
		Queue* node = Q->next;
		Q->next->next->pre = Q;
		Q->next = Q->next->next;
		return node;
	}
}
Tree* createTree() {
	Tree* root1 = (Tree*)malloc(sizeof(Tree));
	root1->data = 'A';
	Tree* root2 = (Tree*)malloc(sizeof(Tree));
	root2->data = 'B';
	Tree* root3 = (Tree*)malloc(sizeof(Tree));
	root3->data = 'C';
	Tree* root4 = (Tree*)malloc(sizeof(Tree));
	root4->data = 'D';
	Tree* root5 = (Tree*)malloc(sizeof(Tree));
	root5->data = 'E';
	Tree* root6 = (Tree*)malloc(sizeof(Tree));
	root6->data = 'F';
	Tree* root7 = (Tree*)malloc(sizeof(Tree));
	root7->data = 'G';
	root1->left = root2;
	root1->right = root3;
	root2->left = root4;
	root2->right = root5;
	root3->left = root6;
	root3->right = root7;
	root4->left = NULL;
	root4->right = NULL;
	root5->left = NULL;
	root5->right = NULL;
	root6->left = NULL;
	root6->right = NULL;
	root7->left = NULL;
	root7->right = NULL;
	return root1;
}
void levelOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	Queue* Q = initQueue();
	enQueue(root, Q);
	while (!isEmpty(Q)) {
		Queue* qnode = deQueue(Q);
		Tree* tnode = qnode->data;
		std::cout << tnode->data << " ";
		if (tnode->left != NULL) {
			enQueue(tnode->left, Q);
		}
		if (tnode->right != NULL) {
			enQueue(tnode->right, Q);
		}
		free(qnode);
	}
	free(Q);
}
int main() {
	Tree* root = createTree();
	levelOrder(root);

	return 0;
}*/
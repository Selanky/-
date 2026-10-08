/*#include<iostream>
#define MAX 100
typedef struct Node {
	int data;
	struct Node* child[MAX];
	int child_count;
}Node;
Node* createNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->child_count = 0;
	return node;
}
void addChild(Node* parent, Node* children) {
	if (parent->child_count < MAX) {
		parent->child[parent->child_count++] = children;
	}
	else {
		std::cout << "Fail!" << std::endl;
	}
}
void DFS(Node* root) {
	if (root == NULL) {
		return;
	}
	std::cout << root->data << " ";
	for (int i = 0;i < root->child_count;i++) {
		DFS(root->child[i]);
	}
}
void BFS(Node* root) {
	Node* Q[MAX];
	int front = 0, rear = 0;
	Q[rear++] = root;
	while (front < rear) {
		Node* current = Q[front++];
		std::cout << current->data << " ";
		for (int i = 0;i < current->child_count;i++) {
			Q[rear++] = current->child[i];
		}
	}
}
int main() {
	Node* n1 = createNode(5);
	Node* n2 = createNode(2);
	Node* n3 = createNode(4);
	Node* n4 = createNode(1);
	Node* n5 = createNode(3);
	addChild(n1, n2);
	addChild(n2, n3);
	addChild(n1, n4);
	addChild(n4, n5);
	DFS(n1);
	std::cout << std::endl;
	BFS(n1);

	return 0;
}*/
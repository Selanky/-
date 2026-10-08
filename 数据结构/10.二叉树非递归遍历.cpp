/*#include<iostream>

typedef struct Tree {
	char data;
	struct Tree* left;
	struct Tree* right;
}Tree;
typedef struct Stack {
	Tree* data;
	struct Stack* next;
}Stack;
Stack* initStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->data = NULL;
	S->next = NULL;
	return S;
}
void push(Tree* data, Stack* S) {
	Stack * node = (Stack*)malloc(sizeof(Stack));
	node->data = data;
	node->next = S->next;
	S->next = node;
}
int isEmpty(Stack* S) {
	if (S->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
Stack* pop(Stack* S) {
	if (isEmpty(S)) {
		return NULL;
	}
	else {
		Stack* node = S->next;
		S->next = node->next;
		return node;
	}
}
Tree* createTree(char data) {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	if (node == NULL) {
		std::cout << "Fail!" << std::endl;
		exit(1);
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void preOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	Stack* S = initStack();
	push(root, S);
	while (!isEmpty(S)) {
		Stack* snode = pop(S);
		Tree* tnode = snode->data;
		std::cout << tnode->data << " ";
		if (tnode->right != NULL) {
			push(tnode->right, S);
		}
		if (tnode->left != NULL) {
			push(tnode->left, S);
		}
	}
}
void inOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	Stack* S = initStack();
	Tree* current = root;
	while (current != NULL || !isEmpty(S)) {
		while (current != NULL) {
			push(current, S);
			current = current->left;
		}
		if (!isEmpty(S)) {
			Stack* snode = pop(S);
			Tree* tnode = snode->data;
			std::cout << tnode->data << " ";
			current = tnode->right;
		}
	}
}
void postOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	Stack* S1 = initStack();
	Stack* S2 = initStack();
	push(root, S1);
	while (!isEmpty(S1)) {
		Stack* snode = pop(S1);
		Tree* tnode = snode->data;
		push(tnode, S2);
		if (tnode->left != NULL) {
			push(tnode->left, S1);
		}
		if (tnode->right != NULL) {
			push(tnode->right, S1);
		}
	}
	while (!isEmpty(S2)) {
		Stack* snode = pop(S2);
		Tree* tnode = snode->data;
		std::cout << tnode->data << " ";
	}
}
int main() {
	Tree* root = createTree('A');
	root->left = createTree('B');
	root->right = createTree('C');
	root->left->left = createTree('D');
	root->left->right = createTree('E');
	root->right->left = createTree('F');
	root->right->right = createTree('G');
	preOrder(root);
	std::cout << std::endl;
	inOrder(root);
	std::cout << std::endl;
	postOrder(root);

	return 0;
}*/
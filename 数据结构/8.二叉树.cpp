/*#include<iostream>

typedef struct Tree {
	char data;
	struct Tree* left;
	struct Tree* right;
}Tree;
Tree* createTree(char data) {
	Tree* T = (Tree*)malloc(sizeof(Tree));
	if (T == NULL) {
		std::cout << "Fail!" << std::endl;
		exit(1);
	}
	T->data = data;
	T->left = NULL;
	T->right = NULL;
	return T;
}
void preOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	std::cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	std::cout << root->data << " ";
	inOrder(root->right);
}
void postOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->data << " ";
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
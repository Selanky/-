#include<iostream>
#include<cstdlib>

typedef struct Tree {
	char data;
	int height;
	struct Tree* left;
	struct Tree* right;
}Tree;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int getHeight(Tree* T) {
	if (T == NULL) {
		return 0;
	}
	return T->height;
}

int getBalance(Tree* T) {
	if (T == NULL) {
		return 0;
	}
	return getHeight(T->left) - getHeight(T->right);
}

Tree* createTree(char data) {
	Tree* T = (Tree*)malloc(sizeof(Tree));
	if (T == NULL) {
		std::cout << "Fail!" << std::endl;
		exit(1);
	}
	T->data = data;
	T->height = 1;
	T->left = NULL;
	T->right = NULL;
	return T;
}

Tree* rightRotate(Tree* y) {
	Tree* x = y->left;
	Tree* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(getHeight(y->left), 
		getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), 
		getHeight(x->right)) + 1;

	return x;
}

Tree* leftRotate(Tree* x) {
	Tree* y = x->right;
	Tree* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(getHeight(x->left), 
		getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), 
		getHeight(y->right)) + 1;

	return y;
}

Tree* insert(Tree* root, char data) {
	if (root == NULL) {
		return createTree(data);
	}
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);
	}
	else {
		return root;
	}

	root->height = max(getHeight(root->left),
		getHeight(root->right)) + 1;

	int balance = getBalance(root);

	if (balance > 1 && data < root->left->data) {
		return rightRotate(root);
	}
	if (balance < -1 && data > root->right->data) {
		return leftRotate(root);
	}
	if (balance > 1 && data > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && data < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void freeTree(Tree* root) {
	if (root == NULL) {
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

void printTree(Tree* root, int level = 0) {
	if (root == NULL) {
		return;
	}
	printTree(root->right, level + 1);
	for (int i = 0; i < level; i++) {
		std::cout << "    ";
	}
	std::cout << root->data << "(h="
		<< root->height << ")" << std::endl;
	printTree(root->left, level + 1);
}

Tree* search(Tree* root, char data) {
	if (root == NULL || root->data == data) {
		return root;
	}
	if (data < root->data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
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
	Tree* root = NULL;

	root = insert(root, 'A');
	root = insert(root, 'B');
	root = insert(root, 'C');
	root = insert(root, 'D');
	root = insert(root, 'E');
	root = insert(root, 'F');
	root = insert(root, 'G');

	std::cout << "PreOrder:  ";
	preOrder(root);
	std::cout << std::endl;

	std::cout << "InOrder:   ";
	inOrder(root);
	std::cout << std::endl;

	std::cout << "PostOrder: ";
	postOrder(root);
	std::cout << std::endl;

	std::cout << "Height:    " 
		<< getHeight(root) << std::endl;

	std::cout << "\nTree Structure:" << std::endl;
	printTree(root);

	char searchVal = 'D';
	Tree* found = search(root, searchVal);
	if (found) {
		std::cout << "\nFound: " << found->data <<
			" (height=" << found->height << ")" << std::endl;
	}
	else {
		std::cout << "\nNot Found: " << searchVal << std::endl;
	}

	freeTree(root);
	return 0;
}

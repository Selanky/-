/*#include<iostream>
#include<cstdlib>

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
	return root;
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

Tree* findMin(Tree* root) {
	while (root && root->left != NULL) {
		root = root->left;
	}
	return root;
}

Tree* deleteNode(Tree* root, char data) {
	if (root == NULL) {
		return NULL;
	}
	if (data < root->data) {
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else {
		if (root->left == NULL) {
			Tree* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Tree* temp = root->left;
			free(root);
			return temp;
		}
		Tree* temp = findMin(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
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

	root = insert(root, 'D');
	root = insert(root, 'B');
	root = insert(root, 'F');
	root = insert(root, 'A');
	root = insert(root, 'C');
	root = insert(root, 'E');
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

	char searchVal = 'C';
	Tree* found = search(root, searchVal);
	if (found) {
		std::cout << "Found: " << found->data << std::endl;
	}
	else {
		std::cout << "Not Found: " << searchVal << std::endl;
	}

	char deleteVal = 'B';
	root = deleteNode(root, deleteVal);
	std::cout << "After delete '" << deleteVal << "', InOrder: ";
	inOrder(root);
	std::cout << std::endl;

	freeTree(root);
	return 0;
}*/
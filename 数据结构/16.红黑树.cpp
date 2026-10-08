/*#include<iostream>

typedef struct Tree {
	int key;
	int color;
	struct Tree* left, * right, * parent;
}Tree;
Tree* createTree(int key) {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->key = key;
	node->color = 0;
	node->left = node->right = node->parent = NULL;
	return node;
}
void leftRotate(Tree** root, Tree* x) {
	if (x == NULL || x->right == NULL) {
		return;
	}
	Tree* y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		*root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}
void rightRotate(Tree** root, Tree* y) {
	if (y == NULL || y->left == NULL) {
		return;
	}
	Tree* x = y->left;
	y->left = x->right;
	if (x->right != NULL) {
		x->right->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == NULL) {
		*root = x;
	}
	else if (y == y->parent->left) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	x->right = y;
	y->parent = x;
}
void insertFixup(Tree** root, Tree* node) {
	while (node != *root && node->parent->color == 0) {
		if (node->parent == node->parent->parent->left) {
			Tree* uncle = node->parent->parent->right;
			if (uncle != NULL && uncle->color == 0) {
				node->parent->color = 1;
				uncle->color = 1;
				node->parent->parent->color = 0;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->right) {
					node = node->parent;
					leftRotate(root, node);
				}
				node->parent->color = 1;
				node->parent->parent->color = 0;
				rightRotate(root, node);
			}
		}
		else {
			Tree* uncle = node->parent->parent->left;
			if (uncle != NULL && uncle->color==0){
				node->parent->color = 1;
				uncle->color = 1;
				node->parent->parent->color = 0;
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->left) {
					node = node->parent;
					rightRotate(root, node);
				}
				node->parent->color = 1;
				node->parent->parent->color = 0;
				leftRotate(root, node);
			}
		}
	}
	(*root)->color = 1;
}
void insertTree(Tree** root, int key) {
	Tree* node = createTree(key);
	Tree* parent = NULL;
	Tree* current = *root;
	while (current != NULL) {
		parent = current;
		if (key < current->key) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	node->parent = parent;
	if (parent == NULL) {
		*root = node;
	}
	else if (key < parent->key) {
		parent->left = node;
	}
	else {
		parent->right = node;
	}
	insertFixup(root, node);
}
void preOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	std::cout << root->key << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	std::cout << root->key << " ";
	inOrder(root->right);
}
void postOrder(Tree* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->key << " ";
}
int main() {
	Tree* root = NULL;
	insertTree(&root, 0);
	insertTree(&root, 7);
	insertTree(&root, 1);
	insertTree(&root, 5);
	insertTree(&root, 3);
	insertTree(&root, 8);
	insertTree(&root, 4);
	insertTree(&root, 2);
	insertTree(&root, 6);
	insertTree(&root, 9);
	preOrder(root);
	std::cout << std::endl;
	inOrder(root);
	std::cout << std::endl;
	postOrder(root);

	return 0;
}*/
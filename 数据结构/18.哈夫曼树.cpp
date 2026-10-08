/*#include<iostream>

typedef struct Tree {
	int weight, parent, left, right;
}Tree;
typedef struct HFTree {
	Tree* data;
	int length;
}HFTree;
HFTree* initTree(int* weight, int length) {
	HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	T->data = (Tree*)malloc(sizeof(Tree) * (2 * length - 1));
	T->length = length;
	for (int i = 0;i < length;i++) {
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].left = -1;
		T->data[i].right = -1;
	}
	return T;
}
int* selectMin(HFTree* T) {
	int min = 10000, min_2nd = 10000, minIndex = -1, min_2ndIndex = -1;
	for (int i = 0;i < T->length;i++) {
		if (T->data[i].parent == 0) {
			if (T->data[i].weight < min) {
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for (int i = 0;i < T->length;i++) {
		if (T->data[i].parent == 0 && i != minIndex) {
			if (T->data[i].weight < min_2nd) {
				min_2nd = T->data[i].weight;
				min_2ndIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = minIndex;
	res[1] = min_2ndIndex;
	return res;
}
void createTree(HFTree* T) {
	int* res;
	int min, min_2nd, length = T->length * 2 - 1;
	for (int i = T->length;i < length;i++) {
		res = selectMin(T);
		min = res[0];
		min_2nd = res[1];
		T->data[i].weight = T->data[min].weight + T->data[min_2nd].weight;
		T->data[i].left = min;
		T->data[i].right = min_2nd;
		T->data[i].parent = 0;
		T->data[min].parent = i;
		T->data[min_2nd].parent = i;
		T->length++;
	}
}
void preOrder(HFTree* T, int index) {
	if (index != -1) {
		std::cout << T->data[index].weight << " ";
		preOrder(T, T->data[index].left);
		preOrder(T, T->data[index].right);
	}
}
void inOrder(HFTree* T, int index) {
	if (index != -1) {
		inOrder(T, T->data[index].left);
		std::cout << T->data[index].weight << " ";
		inOrder(T, T->data[index].right);
	}
}
void postOrder(HFTree* T, int index) {
	if (index != -1) {
		postOrder(T, T->data[index].left);
		postOrder(T, T->data[index].right);
		std::cout << T->data[index].weight << " ";
	}
}
int main() {
	int weight[10] = { 0,3,5,2,8,1,7,4,9,6 };
	HFTree* T = initTree(weight, 10);
	createTree(T);
	preOrder(T, T->length - 1);
	std::cout << std::endl;
	inOrder(T, T->length - 1);
	std::cout << std::endl;
	postOrder(T, T->length - 1);

	return 0;
}*/
/*#include<iostream>

typedef struct Tree {
    char data;
    struct Tree* left;
    struct Tree* right;
    int ltag;  // 0表示指向左孩子，1表示指向前驱
    int rtag;  // 0表示指向右孩子，1表示指向后继
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
    T->ltag = 0;
    T->rtag = 0;
    return T;
}
void preThread(Tree* root, Tree*& prev) {
    if (root == NULL) {
        return;
    }
    // 处理当前节点的左指针
    if (root->left == NULL) {
        root->left = prev;
        root->ltag = 1;
    }
    // 处理前驱节点的右指针
    if (prev != NULL && prev->right == NULL) {
        prev->right = root;
        prev->rtag = 1;
    }
    prev = root;
    // 只有左孩子是实际节点时才递归左子树
    if (root->ltag == 0) {
        preThread(root->left, prev);
    }
    // 只有右孩子是实际节点时才递归右子树
    if (root->rtag == 0) {
        preThread(root->right, prev);
    }
}
void createPreThread(Tree* root) {
    Tree* prev = NULL;
    if (root != NULL) {
        preThread(root, prev);
        // 处理最后一个节点
        if (prev != NULL) {
            prev->right = NULL;
            prev->rtag = 1;
        }
    }
}

// 先序遍历线索二叉树
void preOrderThread(Tree* root) {
    Tree* p = root;
    while (p != NULL) {
        std::cout << p->data << " ";
        // 如果有左孩子，移动到左孩子
        if (p->ltag == 0) {
            p = p->left;
        }
        // 否则移动到后继
        else {
            p = p->right;
        }
    }
}
Tree* preNext(Tree* node) {
    if (node->ltag == 0) {
        return node->left;  // 有左孩子，后继为左孩子
    }
    return node->right;     // 无左孩子，后继为右指针指向的节点
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

    // 创建先序线索二叉树
    createPreThread(root);
    preOrderThread(root);
    std::cout << std::endl;
    Tree* eNode = root->left->right;
    Tree* next = preNext(eNode);
    if (next != NULL) {
        std::cout << next->data << std::endl;
    }
    else {
        std::cout << "NULL" << std::endl;
    }

    return 0;
}*/
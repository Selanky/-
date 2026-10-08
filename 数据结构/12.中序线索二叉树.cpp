/*#include<iostream>

typedef struct Tree {
    char data;
    struct Tree* left;
    struct Tree* right;
    int ltag;  
    int rtag;  
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
void inThread(Tree* root, Tree*& prev) {
    if (root == NULL) {
        return;
    }
    if (root->ltag == 0) {
        inThread(root->left, prev);
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
    if (root->rtag == 0) {
        inThread(root->right, prev);
    }
}
void createInThread(Tree* root) {
    Tree* prev = NULL;
    if (root != NULL) {
        inThread(root, prev);
        // 处理最后一个节点
        if (prev != NULL) {
            prev->right = NULL;
            prev->rtag = 1;
        }
    }
}
void inOrderThread(Tree* root) {
    Tree* p = root;
    // 找到中序遍历的第一个节点（最左节点）
    while (p->ltag == 0) {
        p = p->left;
    }
    while (p != NULL) {
        std::cout << p->data << " ";
        // 如果右指针是线索，直接到达后继
        if (p->rtag == 1) {
            p = p->right;
        }
        else {
            // 否则找到右子树的最左节点
            p = p->right;
            while (p != NULL && p->ltag == 0) {
                p = p->left;
            }
        }
    }
}
Tree* inNext(Tree* node) {
    if (node->rtag == 1) {
        return node->right;     // 右指针是线索，直接指向后继
    }
    // 否则返回右子树的最左节点
    Tree* p = node->right;
    while (p->ltag == 0) {
        p = p->left;
    }
    return p;
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

    // 创建中序线索二叉树
    createInThread(root);
    inOrderThread(root);
    std::cout << std::endl;
    Tree* eNode = root->left->right;
    Tree* next = inNext(eNode);
    if (next != NULL) {
        std::cout << next->data << std::endl;
    }
    else {
        std::cout << "NULL" << std::endl;
    }

    return 0;
}*/
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
void postThread(Tree* root, Tree*& prev) {
    if (root == NULL) {
        return;
    }
    if (root->ltag == 0) {
        postThread(root->left, prev);
    }
    if (root->rtag == 0) {
        postThread(root->right, prev);
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
}
void createPostThread(Tree* root) {
    Tree* prev = NULL;
    if (root != NULL) {
        postThread(root, prev);
        // 处理最后一个节点：仅当它没有右孩子时才设为线索
        if (prev != NULL && prev->right == NULL) {
            prev->right = NULL;
            prev->rtag = 1;
        }
    }
}
Tree* postFirst(Tree* root) {
    Tree* p = root;
    while (true) {
        if (p->ltag == 0) {
            p = p->left;
        }
        else if (p->rtag == 0) {
            p = p->right;
        }
        else {
            break;
        }
    }
    return p;
}

Tree* findParent(Tree* root, Tree* node, bool& isLeft) {
    if (root == NULL || node == NULL) {
        return NULL;
    }
    if (root->ltag == 0 && root->left == node) {
        isLeft = true;
        return root;
    }
    if (root->rtag == 0 && root->right == node) {
        isLeft = false;
        return root;
    }
    Tree* leftRes = NULL;
    if (root->ltag == 0) {
        leftRes = findParent(root->left, node, isLeft);
    }
    if (leftRes != NULL) {
        return leftRes;
    }
    if (root->rtag == 0) {
        return findParent(root->right, node, isLeft);
    }
    return NULL;
}

Tree* postNext(Tree* root, Tree* p) {
    if (p->rtag == 1) {
        return p->right;
    }
    bool isLeft;
    Tree* parent = findParent(root, p, isLeft);
    if (parent == NULL) {
        return NULL;
    }
    if (isLeft) {
        if (parent->rtag == 0) {
            return postFirst(parent->right);
        }
        else {
            return parent;
        }
    }
    else {
        return parent;
    }
}

void postOrderThread(Tree* root) {
    if (root == NULL) {
        return;
    }
    Tree* p = postFirst(root);
    while (p != NULL) {
        std::cout << p->data << " ";
        p = postNext(root, p);
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
    Tree* root = createTree('A');
    root->left = createTree('B');
    root->right = createTree('C');
    root->left->left = createTree('D');
    root->left->right = createTree('E');
    root->right->left = createTree('F');
    root->right->right = createTree('G');

    // 创建后序线索二叉树
    createPostThread(root);
    postOrderThread(root);
    std::cout << std::endl;
    Tree* eNode = root->left->right;
    Tree* next = postNext(root, eNode);
    if (next != NULL) {
        std::cout << next->data << std::endl;
    }
    else {
        std::cout << "NULL" << std::endl;
    }

    return 0;
}*/
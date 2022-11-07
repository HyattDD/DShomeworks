#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 封装数据，数据需要关键字，和C++中的pair是类似的
// 指针一般都是前面用LP前缀表示，方便阅读
typedef struct data {
    int first;
    char second[20];
}DATA, *LPDATA;

// 二叉搜索树的结点
typedef struct binTreeNode {
    DATA data;
    struct binTreeNode* lchild;
    struct binTreeNode* rchild;
}NODE, *LPNODE;

// 用面向对象的思想做
typedef struct binSearchTree {
    NODE* root;
    int treeSize;
}BTREE, *LPBTREE;

// 插入结点
LPNODE createNode(DATA element) {
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->data = element;
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;
    return newNode;
}

// 创建二叉搜索树
LPBTREE createBinarySearchTree() {
    LPBTREE tree = (LPBTREE)malloc(sizeof(BTREE));
    tree->root = nullptr;
    tree->treeSize = 0;
    return tree;
}

// 求树的size
int size(LPBTREE tree) {
    return tree->treeSize;
}

// 判断树空与否
bool empty(LPBTREE tree) {
    if (tree->treeSize == 0) return true;
    return false;
}

// 插入结点，自动构建结点
void insertNode (LPBTREE tree, DATA element) {
    LPNODE moveNode = tree->root;
    LPNODE moveParentNode = nullptr; // 记录移动之前的结点
    while (moveNode != nullptr) {
        moveParentNode = moveNode;
        if (element.first < moveNode->data.first) {
            //  小则插到左边
            moveNode = moveNode->lchild;
        } else if (element.first > moveNode->data.first) {
            // 大则插到右边
            moveNode = moveNode->rchild;
        } else {
            // 相同则更新替换
            strcpy(moveNode->data.second, element.second);
            return;
        }
    }

    // 完成上面循环表示找到插入位置了
    LPNODE newNode = createNode(element);
    // 插入的位置是移动结点的父结点
    if (tree->root == nullptr) {
        tree->root = newNode;
    } else if (moveParentNode->data.first > element.first) {
        moveParentNode->lchild = newNode;
    } else if (moveParentNode->data.first < element.first) {
        moveParentNode->rchild = newNode;
    }
    
}

void printTree(LPNODE root) {
    if (root != nullptr) {
        printTree(root->lchild);
        printf("%d\t%s\n", root->data.first, root->data.second);
        printTree(root->rchild);
    }
}

// 中序遍历测试
void printInOrder(LPBTREE tree) {
    printTree(tree->root);
}

int main() {
    DATA arrData[8] = {100, "John", 88, "Tom", 92, "Green", 66, "Jimmy", 
    97, "Mary", 77, "Loki", 78, "Thor", 99, "Andy"};
    LPBTREE tree = createBinarySearchTree();
    for (int i = 0; i < 8; i++) {
        insertNode(tree, arrData[i]);
    } 
    printInOrder(tree);
    return 0;
}
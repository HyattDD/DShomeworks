/*中缀输出表达式树，可以带括号也可以不带*/

#include <stdio.h>
#include <stdlib.h>

#define EleType char

// 定义树结点的结构体
typedef struct BinTreeNode {
    EleType data;
    BinTreeNode* lchild;
    BinTreeNode* rchild;
}BinTreeNode;


// 定义创建树结点的函数
BinTreeNode* createNode(EleType data) {
    BinTreeNode* newNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// 定义插入结点的函数
void insertNode (BinTreeNode* curNode, BinTreeNode* lchildNode, BinTreeNode* rchildNode) {
    curNode->lchild = lchildNode;
    curNode->rchild = rchildNode;
}

// 遍历到某一结点时打印其data
void visit(BinTreeNode* tree) {
    printf("%c ", tree->data);
}


// 中序遍历
void inOrder(BinTreeNode* tree) {
    if (tree != NULL) {
        inOrder(tree->lchild);
        visit(tree);
        inOrder(tree->rchild);
    }
}

int main() {
    // 创建树的结点
    BinTreeNode* A = createNode('*');
    BinTreeNode* B = createNode('+');
    BinTreeNode* C = createNode('-');
    BinTreeNode* D = createNode('x');
    BinTreeNode* E = createNode('y');
    BinTreeNode* F = createNode('m');
    BinTreeNode* G = createNode('n');

    // 连接树的结点
    insertNode(A, B, C);
    insertNode(B, D, E);
    insertNode(C, F, G);

    // 打印树的图形
    printf("The origin tree looks like: \n");
    printf("       *           \n");
    printf("     /   \\        \n");
    printf("    +      -       \n");
    printf("   / \\    /  \\   \n");
    printf(" x    y   m    n   \n");


    // 输出中序遍历表达式树的结果
    printf("InOrder traverse: ");
    inOrder(A);
    printf("\n");


}



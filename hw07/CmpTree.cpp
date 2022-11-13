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

// 判断两棵树是否相等
bool IsEqual(BinTreeNode* root01, BinTreeNode* root02) {
    if (root01 == nullptr && root02 == nullptr) return true;
    if (root01 != nullptr && root02 != nullptr) {
        if (root01->data != root02->data) return false;
        if (!IsEqual(root01->lchild, root02->lchild)) return false;
        if (!IsEqual(root01->rchild, root02->rchild)) return false;
        return true;
    }
    return false;
}


int main() {

    // 创建树的结点
    BinTreeNode* A = createNode('1');
    BinTreeNode* B = createNode('2');
    BinTreeNode* C = createNode('3');
    BinTreeNode* D = createNode('4');
    BinTreeNode* E = createNode('1');
    BinTreeNode* F = createNode('2');
    BinTreeNode* G = createNode('3');
    BinTreeNode* H = createNode('5');

    // 连接树的结点
    insertNode(A, B, C);
    insertNode(B, D, nullptr);
    insertNode(E, F, G);
    insertNode(F, H, nullptr);

    // 打印树的图形
    printf("The origin tree01 looks like: \n");
    printf("       1           \n");
    printf("     /   \\        \n");
    printf("    2     3        \n");
    printf("   /               \n");
    printf(" 4                 \n");

    printf("The origin tree02 looks like: \n");
    printf("       1           \n");
    printf("     /   \\        \n");
    printf("    2     3        \n");
    printf("   /               \n");
    printf(" 5                 \n");

    if (IsEqual(A, E)) {
        printf("These two trees are same.\n");
    } else printf("These two trees are not same.\n");

}



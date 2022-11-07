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

// 前序遍历
void preOrder(BinTreeNode* tree) {
    if (tree != NULL) {
        visit(tree);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}

// 中序遍历
void inOrder(BinTreeNode* tree) {
    if (tree != NULL) {
        inOrder(tree->lchild);
        visit(tree);
        inOrder(tree->rchild);
    }
}

// 后序遍历
void postOrder(BinTreeNode* tree) {
    if (tree != NULL) {
        postOrder(tree->lchild);
        postOrder(tree->rchild);
        visit(tree);
    }
}

// 深度遍历求二叉树的结点个数
int dfs(BinTreeNode* root) {
    if (root->lchild == nullptr && root->rchild == nullptr) {
        return 1;
    }
    int res = 0;
    if (root->lchild) res += dfs(root->lchild);
    if (root->rchild) res += dfs(root->rchild);
    return res;
}

int height(BinTreeNode* root) {
    return 0;
}




int main() {

    // 创建树的结点
    BinTreeNode* A = createNode('A');
    BinTreeNode* B = createNode('B');
    BinTreeNode* C = createNode('C');
    BinTreeNode* D = createNode('D');
    BinTreeNode* E = createNode('E');
    BinTreeNode* F = createNode('F');
    BinTreeNode* G = createNode('G');
    BinTreeNode* H = createNode('H');
    BinTreeNode* I = createNode('I');

    // 连接树的结点
    insertNode(A, B, C);
    insertNode(B, D, NULL);
    insertNode(C, E, F);
    insertNode(E, NULL, G);
    insertNode(F, H, I);

    // 打印树的图形
    printf("The origin tree looks like: \n");
    printf("       A           \n");
    printf("     /   \\        \n");
    printf("    B     C        \n");
    printf("   /     /  \\     \n");
    printf(" D      E    F     \n");
    printf("         \\  / \\  \n");
    printf("         G  H  I   \n"); 

    // 输出树结点数
    printf("This tree has %d nodes in total. \n", dfs(A));   

    // 输出前、中、后序遍历结果
    printf("PreOrder traverse: ");
    preOrder(A); 
    printf("\n");

    printf("InOrder traverse: ");
    inOrder(A);
    printf("\n");

    printf("PostOrder traverse: ");
    postOrder(A);     
    printf("\n");

}



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


// 深度遍历求二叉树的结点个数
int dfs(BinTreeNode* root) {
    if (root == nullptr) return 0;
    if (root->lchild == nullptr && root->rchild == nullptr) return 1;
    int res = 0;
    if (root->lchild) res += dfs(root->lchild);
    if (root->rchild) res += dfs(root->rchild);
    return res;
}

// 返回二叉树中任意两结点的最近公共祖先
BinTreeNode* nearestCommonAncestor(BinTreeNode* root, BinTreeNode* p, BinTreeNode* q) {
    if (root == nullptr || p == root || q == root) return root;
    BinTreeNode* left = nearestCommonAncestor(root->lchild, p, q);
    BinTreeNode* right = nearestCommonAncestor(root->rchild, p, q);
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    return root;
}

// 返回二叉树中某结点到其某个祖先的距离，也即二者的层数差
int selfToAncestor(BinTreeNode* ancestor, BinTreeNode* node, int level = 0) {
    if (ancestor == nullptr || node == nullptr) return -1;
    if (ancestor->data == node->data) return level;
    int res = selfToAncestor(ancestor->lchild, node, level + 1);
    if (res == -1) return selfToAncestor(ancestor->rchild, node, level + 1);
    else return res;
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

    // 求出二叉树中两个结点的最近距离，实际上也利用了之前的求最近公共祖先的算法
    BinTreeNode* ancestor = nearestCommonAncestor(A, G, I);
    int distance = selfToAncestor(ancestor, G) + selfToAncestor(ancestor, I);
    printf("The shortest distance from G to I is : %d \n", distance);
}



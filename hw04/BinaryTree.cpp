#include <stack>
#include <queue>
#include "BinaryTree.hpp"

// 构造与析构函数
template <class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
}
template <class T>
BinaryTree<T>::~BinaryTree() {
    DeleteBinaryTree(root);
}

// 判断树空
template <class T>
bool BinaryTree<T>::isEmpty() const{
    return this->root == NULL;
}

// 获取当前树的根结点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Root() {
    return this->root;
}

// 获取树中某结点的父结点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current) {
    using std::stack;
    stack< BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = this->root;
    if (root != NULL && current != NULL) {
        while (!aStack.empty() || pointer) {
            if (pointer != NULL) {
                // 如果pointer的孩子是current则返回parent
                if (current == pointer->left_child() || current == pointer->right_child) 
                    return pointer;
                aStack.push(pointer);
                pointer = pointer->left_child();
            } else {
                pointer = aStack.top();
                aStack.pop();
                pointer = pointer->right_child();
            }
        }
    }
}

// 获取树中某结点的左孩子
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* current) {
    return current->lchild;
}

// 获取树中某结点的右孩子
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* current) {
    return current->rchild;
}

// 构建树🌲
template <class T>
void BinaryTree<T>::CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree) {
    this->root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);
    // 将原来的两颗子树的根结点置为空，避免非法访问
    leftTree.root = rightTree.root = NULL; 
}

// 先序遍历，递归
template <class T>
void BinaryTree<T>::PreOrder(const BinaryTreeNode<T> *root) {
    if (root != NULL) {
        Visit(root->value());
        PreOrder(root->left_child());
        PreOrder(root->right_child());
    }
}

// 先序遍历，非递归
//TODO

// 中序遍历，递归
template <class T>
void BinaryTree<T>::InOrder(const BinaryTreeNode<T> *root) {
    if (root != NULL) {
        InOrder(root->left_child());
        Visit(root->value());
        InOrder(root->right_child());
    }
}

// 中序遍历，非递归
//TODO


// 后序遍历，递归
template <class T>
void BinaryTree<T>::PostOrder(const BinaryTreeNode<T> *root) {
    if (root != NULL) {
        PostOrder(root->left_child());
        PostOrder(root->right_child());
        Visit(root->value());
    }
}

// 后序遍历，非递归
//TODO

// 层序遍历
template <class T>
void BinaryTree<T>::LevelOrder(const BinaryTreeNode<T> *root) {
    using std::queue;
    queue < BinaryTreeNode<T>* > aQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer) {
        aQueue.push(pointer);
    }
    while (!aQueue.empty()) {
        pointer = aQueue.front();
        aQueue.pop();
        Visit(pointer->value);
        if (pointer->left_child() != NULL) 
            aQueue.push(pointer->left_child());
        if (pointer->right_child() != NULL)
            aQueue.push(pointer->right_child());
    }
}

// 后序遍历删除二叉树
template <class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *root) {
    if (root != NULL) {
        DeleteBinaryTree(root->lchild);
        DeleteBinaryTree(root->rchild);
        delete root;
    }
}

/*--------------以下四个函数是求解main.cpp中作业题的关键函数----------------*/

// 获取叶节点个数
template <class T>
int BinaryTree<T>::GetLeafNumber() {
    if (this->root == NULL) return 0;
    if (this->root->isLeaf()) return 1;
    return GetLeafNumber(this->root->left_child()) + GetLeafNumber(this->root->right_child());
}

// 获取树高，空树高度为0
template <class T>
int BinaryTree<T>::GetTreeHeight(BinaryTreeNode<T> *root) {
    if (root == NULL) return 0;
    int lh = GetTreeHeight(root->left_child);
    int rh = GetTreeHeight(root->right_child);
    return lh > rh ? lh + 1 : rh + 1;
}

// 交换树中结点的左右孩子结点
template <class T>
void BinaryTree<T>::ReverseLR(BinaryTreeNode<T> *root) {
    BinaryTreeNode<T> *tmp;
    if (root != NULL) {
        tmp = root->left_child();
        root->left_child() = root->right_child();
        root->right_child() = tmp;
        ReverseLR(root->left_child());
        ReverseLR(root->right_child());
    }
}

// 求两个结点的公共最近祖先结点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::NearestAncestor(BinaryTreeNode<T>* a, BinaryTreeNode<T>* b) {


}



#include "BinaryTree.hpp"

// 先序遍历，递归
template <class T>
void BinaryTree<T>::PreOrder(const BinaryTreeNode<T> *root) {
    if (root != nullptr) {
        Visit(root->value);
        PreOrder(root->left_child);
        PreOrder(root->right_child);
    }
}

// 先序遍历，非递归
//TODO

// 中序遍历，递归
template <class T>
void BinaryTree<T>::InOrder(const BinaryTreeNode<T> *root) {
    if (root != nullptr) {
        InOrder(root->left_child);
        Visit(root->value);
        InOrder(root->right_child);
    }
}

// 中序遍历，非递归
//TODO


// 后序遍历，递归
template <class T>
void BinaryTree<T>::PostOrder(const BinaryTreeNode<T> *root) {
    if (root != nullptr) {
        PostOrder(root->left_child);
        PostOrder(root->right_child);
        Visit(root->value);
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
        if (pointer->left_child() != nullptr) 
            aQueue.push(pointer->left_child());
        if (pointer->right_child() != nullptr)
            aQueue.push(pointer->right_child());
    }
}


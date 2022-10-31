#include <iostream>
#include "BinaryTreeNode.hpp"

// 构造函数
template <class T>
BinaryTreeNode<T>::BinaryTreeNode() {}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& val){
    this->info = val;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& val, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) {
    this->info = val;
    this->lchild = l;
    this->rchild = r;
}

// 析构函数，释放结点
template <class T>
BinaryTreeNode<T>::~BinaryTreeNode() {}

// 获取当前结点的值
template <class T>
T BinaryTreeNode<T>::value() const {
    return this->info;
}

// 返回当前结点的左孩子结点
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::left_child() const {
    return this->lchild;
}

// 返回当前结点的右孩子结点
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::right_child() const {
    return this->rchild;
}

// 设置当前结点的左右孩子结点
template <class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* node) {
    this->lchild = node;
}

template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* node) {
    this->rchild = node;
}

// 设置当前结点的值
template <class T>
void BinaryTreeNode<T>::setValue(const T& val) {
    this->info = val;
}

// 判断当前结点是否为叶子🍃结点
template <class T>
bool BinaryTreeNode<T>::isLeaf() const{
    return (this->rchild == NULL) && (this->lchild == NULL);
}

// 将赋值运算符进行重载，用于将一个结点直接赋值给某个结点
template <class T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(const BinaryTreeNode<T>& node) {
    this->info = node.info;
    this->lchild = node.lchild;
    this->rchild = node.rchild;
    this->parent = node.parent;
    return *this;
}

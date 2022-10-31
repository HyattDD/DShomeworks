#pragma once
#include "BinaryTree.hpp"

// 头文件互相引用，为了避免编译出错，要声明一下incude的类
template <class T>
class BinaryTree;

template <class T> 
class BinaryTreeNode{
    friend class BinaryTree<T>;

    private:
        // 结点数据域
        T info;
        // 父结点，左、右孩子结点
        BinaryTreeNode<T> *lchild;
        BinaryTreeNode<T> *rchild;

    public:
        // 构造函数
        BinaryTreeNode();
        BinaryTreeNode(const T& element);
        BinaryTreeNode(const T& element, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);

        // 析构函数
        ~BinaryTreeNode();

        // 获取结点内容 
        T value() const;

        // 获取结点的左右孩子结点
        BinaryTreeNode<T> *left_child() const;
        BinaryTreeNode<T> *right_child() const;

        // set方法
        void setLeftChild(BinaryTreeNode<T>* node);
        void setRightChild(BinaryTreeNode<T>* node);
        void setValue(const T& val);

        // 判断是否是叶子结点
        bool isLeaf() const;

        // 将等于号=进行运算符重载
        BinaryTreeNode<T>& operator=(const BinaryTreeNode<T>& node);
};



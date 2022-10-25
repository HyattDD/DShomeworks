#pragma once

template <class T> 
class BinaryTreeNode{
    friend class BinaryTree<T>;
    private:
        // 结点数据域
        T info;
    public:
        // 构造函数
        BinaryTreeNode();
        BinaryTreeNode(const T& element);
        BinaryTreeNode(const T& element, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);
        // 析构函数
        ~BinaryTreeNode();
        // const means that the method promises not to alter any members of the class. 
        T value() const;
        BinaryTreeNode<T> *left_child() const;
        BinaryTreeNode<T> *right_child() const;
        // set方法
        void setLeftChild(BinaryTreeNode<T> *);
        void setRightChild(BinaryTreeNode<T> *);
        void setValue(const T& val);
        // 判断是否是叶子结点
        bool isLeaf() const;
        // 将等于号=进行运算符重载
        BinaryTreeNode<T>& operator=(const BinaryTreeNode<T>& node);
};



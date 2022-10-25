#pragma once
#include "BinaryTreeNode.hpp"

template <class T>
class BinaryTree {
    private:
        BinaryTreeNode<T>* root;
    public:
        // 构造函数与析构函数
        BinaryTree() {
            root = nullptr;
        }
        ~BinaryTree() {
            DeleteBinaryTree(root);
        }

        // 判断树空
        bool isEmpty() const;

        // 获取当前树的根节点
        BinaryTreeNode<T>* Root();

        // 获取当前结点的父结点、左右兄弟结点
        BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);
        BinaryTreeNode<T>* LeftSibling(BinaryTree<T>* current);
        BinaryTreeNode<T>* RightSibling(BinaryTree<T>* current);

        // 创建一个树
        void CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);

        // 前序遍历，递归
        void PreOrder(const BinaryTreeNode<T> *root);   

        // 前序遍历，非递归
        void PreOrderWithoutRecursion(BinaryTreeNode<T> *root);   

        // 中序遍历，递归
        void InOrder(const BinaryTreeNode<T> *root);       
        
        // 中序遍历，非递归
        void InOrderWithoutRecursion(BinaryTreeNode<T> *root);   

        // 后序遍历，递归
        void PostOrder(const BinaryTreeNode<T> *root);    

        // 后序遍历，非递归
        void PostOrderWithoutRecursion(const BinaryTreeNode<T> *root);     

        // 层序遍历
        void LevelOrder(const BinaryTreeNode<T> *root);    

        // 删除二叉树
        void DeleteBinaryTree(BinaryTreeNode<T> *root);

};
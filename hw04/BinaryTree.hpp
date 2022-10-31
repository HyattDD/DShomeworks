#pragma once
#include "BinaryTreeNode.hpp"

// 头文件互相引用，为了避免编译出错，要声明一下incude的类
template <class T>
class BinaryTreeNode;

template <class T>
class BinaryTree {
    private:
        BinaryTreeNode<T>* root;
    public:
        // 构造函数与析构函数
        BinaryTree();
        ~BinaryTree();

        // 判断树空
        bool isEmpty() const;

        // 获取当前树的根节点
        BinaryTreeNode<T>* Root();

        // 获取当前结点的父结点、左右兄弟结点
        BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);
        BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* current);
        BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* current);

        // 根据用户输入的结点信息创建一个树
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


        /*--------------以下四个函数是求解main.cpp中作业题的关键函数----------------*/

        // 获取当前二叉树的叶节点的个数
        int GetLeafNumber();

        // 计算二叉树的高度，空树高度为0
        int GetTreeHeight(BinaryTreeNode<T> *root);

        // 镜面影射算法，将二叉树的每一个结点的左右结点互换
        void ReverseLR(BinaryTreeNode<T> *root);

        // 输入两个结点，返回距离这个结点距离最近的公共祖先结点
        BinaryTreeNode<T>* NearestAncestor(BinaryTreeNode<T> *a, BinaryTreeNode<T> *b);

};
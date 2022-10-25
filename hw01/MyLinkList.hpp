#pragma once
#include <iostream>
// 定义链表中节点的结构体
struct LinkListNode{
    int val;
    LinkListNode *next;
    // 结构体构造函数
    LinkListNode(int val) : val(val), next(nullptr){}
};

class MyLinkList { 
    private:
        int _size;
        LinkListNode *_dummyHead;
    public:
        // 构造函数，初始化链表,构造一个虚拟头节点，且节点值为0，等于是无节点的真空链表
        MyLinkList();
        // 获取到第n个节点的值
        int getValue(int index);

        // 在链表的头部插入一个节点
        void addHead(int val);

        // 在链表的尾部添加一个节点
        void addTail(int val);

        // 在指定的位置插入节点
        void addIndex(int index, int val);

        // 删除制定位置的元素
        void deleteIndex(int index);

        // 打印整个链表
        void printLinkList();

        // 获取链表中最大的节点值
        int getMax();

        // 删除链表中处于(i,k)范围内的数字
        void delEle(int i , int k);

        // 通过遍历一趟，将链表中所有结点的链接方向逆转
        void reverse();

        // 获取链表的虚头节点
        LinkListNode* get_dummyHead() {
            return this->_dummyHead;
        }

        // 合并成非递减函数
        void mergeToNonDecreasingList(MyLinkList list);

        // 合并成非递增函数
        void mergeToNonIncreasingList(MyLinkList list);
};
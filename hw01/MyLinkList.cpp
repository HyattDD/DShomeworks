#include "MyLinkList.hpp"
#include <iostream>
#include <cassert>
using namespace std;
// 构造函数，初始化链表,构造一个虚拟头节点，且节点值为0，等于是无节点的真空链表
MyLinkList :: MyLinkList() {
    _dummyHead = new LinkListNode(0);
    _size = 0;
}

// 获取index下标位置元素
int MyLinkList :: getValue (int index) {
    // 先判断是否越界
    if (index < 0 || index >= _size)
    {
        return -1;
    }
    LinkListNode *cursor = _dummyHead->next;
    while (index--)
    {
        cursor = cursor->next;
    }
    return cursor->val;
}

// 在头部插入新节点
void MyLinkList :: addHead(int val) {
    LinkListNode* newNode = new LinkListNode(val);
    newNode->next = _dummyHead->next;
    _dummyHead->next = newNode;
    _size++;
}

// 在尾部插入新节点
void MyLinkList :: addTail(int val) {
    LinkListNode* newNode = new LinkListNode(val);
    LinkListNode* cursor = _dummyHead;
    while (cursor->next != nullptr)
    {
        cursor = cursor->next;
    }
    cursor->next = newNode;
    _size++;
}

// 在指定的下标处插入新节点
void MyLinkList :: addIndex(int index, int val) {
    // 检验下标是否越界
    if (index < 0 || index >= _size) {
        return;
    }
    LinkListNode* newNode = new LinkListNode(val);
    LinkListNode* cursor = _dummyHead;
    while (index--)
    {
        cursor = cursor->next;   
    }
    newNode->next = cursor->next;
    cursor->next = newNode;
    _size++;
}

// 删除指定位置的节点
void MyLinkList :: deleteIndex(int index) {
    if (index < 0 || index >= _size)
    {
        return;
    }
    LinkListNode* cursor = _dummyHead;
    while (index--)
    {
        cursor = cursor->next;
    }
    LinkListNode* tmp = cursor->next;
    cursor->next = cursor->next->next;
    delete tmp;
    _size--;
}

// 打印整个链表
void MyLinkList :: printLinkList() {
    LinkListNode* cursor = _dummyHead;
    while (cursor->next != nullptr)
    {
        cout << cursor->next->val << " ";
        cursor = cursor->next;
    }
    cout << endl;
}

// 01 原地和某个非递减链表合并得到新的非递减链表，且去除重复元素
void MyLinkList :: mergeToNonDecreasingList(MyLinkList list) {
    LinkListNode* r = this->_dummyHead;  
    LinkListNode* p = this->_dummyHead->next;
    LinkListNode* q = list.get_dummyHead()->next;
    while (p && q) {
        if (p->val < q->val) {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else if (p->val == q->val)
        {
            while (p->val == q->val) q = q->next;
            p = p->next;
        }
        else {
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }
    if (!p) r->next = q;
    if (!q) r->next = p;
}

// 02 原地和某个非递减链表合并成新的非递增链表，且去除重复元素，调用上面的函数并reverse即可
void MyLinkList :: mergeToNonIncreasingList(MyLinkList list) {
    this->mergeToNonDecreasingList(list);
    this->reverse();
}

// 03 获取链表的最大值
int MyLinkList :: getMax() {
    int res = INT_MIN;
    LinkListNode* cursor = _dummyHead;
    while (cursor->next != nullptr)
    {
        if (cursor->next->val > res) {
            res = cursor->next->val;
        }
        cursor = cursor->next;
    }
    return res;
} 


// 05 删除递增有序链表中值大于i但是小于k的节点
void MyLinkList :: delEle(int i , int k) {
    LinkListNode* cursor = _dummyHead;
    while (cursor->next != nullptr)
    {
        if ((cursor->next->val > i) && (cursor->next->val < k))
        {
            LinkListNode* temp = cursor->next;
            cursor->next = cursor->next->next;
            delete temp;
        } else {
            cursor = cursor->next;
        }    
    }
}


// 04 不改变链表中元素的存储位置，将链表逆转，主要思想是头插法
void MyLinkList :: reverse() {
    LinkListNode* cursor = _dummyHead;
    LinkListNode *p, *q;
    p = cursor->next;
    cursor->next = NULL;  //将头结点置为为尾结点
    while(p!=NULL){
        q = p->next;
        p->next = cursor->next;  // 头插法 将指针域转为指向前一个结点
        cursor->next = p;  //不断将头结点next指针指向下一个新的结点
        p = q;
    }
}
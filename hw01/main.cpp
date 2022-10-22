#include <iostream>
#include "MyLinkList.hpp"

int main () {
    // 定义链表,分别为5个题目所使用
    MyLinkList linkList01, linkList02;
    MyLinkList L1, L2;
    MyLinkList linklist03, linkList04, linkList05;

    // 准备好初始的两个非递减的链表中的元素数据
    int a[10] = {1, 3, 4, 4, 5, 7, 7, 8, 9, 14};
    int b[10] = {2, 4, 5, 7, 9, 12, 13, 15, 18, 20};
    // 设置问题5中要剔除节点的范围
    int i = 3, k = 12;

    // 用准备好的数据初始化链表
    for (size_t i = 0; i < 10; i++)
    {
        linkList01.addTail(a[i]);
        linkList02.addTail(b[i]);
        L1.addTail(a[i]);
        L2.addTail(b[i]);
        linklist03.addTail(a[i]);
        linkList04.addTail(a[i]);
        linkList05.addTail(a[i]);
    }

    // 打印两个链表
    std::cout << "linklist01 is :" << std::endl;
    linkList01.printLinkList();

    std::cout << "linklist02 is :" << std::endl;
    linkList02.printLinkList();
    
    // 01.合并链表，合并结果为非递减，且无重复元素
    linkList01.mergeToNonDecreasingList(linkList02);
    std::cout << "The merged Non-Decreasing linked list is:" << std::endl;
    linkList01.printLinkList();

    // 02.合并链表，合并结果为非递增，且无重复元素
    L1.mergeToNonIncreasingList(L2);
    std::cout << "The merged Non-Increasing linked list is:" << std::endl;
    L1.printLinkList();
    
    // 03.通过一趟遍历确定单链表中值最大的结点
    int MaxElement = linkList01.getMax();
    std::cout << "03. The greatest number of linklist01 : " << MaxElement << std::endl;

    // 04.一趟遍历原地反转链表
    linkList01.reverse();
    std::printf("04. The reversed linklist01 : ");
    linkList01.printLinkList();

    //05.删除递增有序链表中值大于i但是小于k的节点
    linkList01.reverse();
    linkList01.delEle(i, k);
    std::printf("05. After delete nodes between (%d, %d), linklist01 : ", i, k);
    linkList01.printLinkList();

    return 0;
}


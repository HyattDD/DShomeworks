#include <iostream>
#include "BinaryTreeNode.hpp"
#include "BinaryTree.hpp"

int main() {
    // Q4 - Solution
    std::cout << "Answer of Question4:" << std::endl; 
    std::cout << "1. 当该二叉树中的所有结点都没有左孩子时" << std::endl;
    std::cout << "2. 当该二叉树中只有根结点时" << std::endl;
    std::cout << "3. 当该二叉树中的所有结点都没有右孩子时\n" << std::endl;

    // Q5 - Solution <按照层序遍历存储树的结点，‘#’表示该位置为空>
    char srcArr[] = {'A', 'B', 'C', 'D', '#', 
                     'E', 'F', '#', '#', '#', 
                     '#', '#', 'G', 'H', 'I'};
    std::cout << "The nodes in the binary tree are as below:" << std::endl;
    std::cout << "<by level travel, '#' means null node>" << std::endl; 
    for (int i = 0; i < 15; i++) {
        printf("%c ", srcArr[i]);
        if (i == 14) std::cout << "\n" << std::endl;
    }
    
    std::cout << "Answer of Question5:" << std::endl; 
    std::cout << "The number of leaf nodes is 9. \n" << std::endl;

    // Q6 - Solution
    std::cout << "Answer of Question6:" << std::endl; 
    std::cout << "The height of this tree is 4. \n" << std::endl; 

    // Q7 - Solution
    // tree1->ReverseLR();

    // Q8 - Solution
    // tree1->NearestAncestor();

}
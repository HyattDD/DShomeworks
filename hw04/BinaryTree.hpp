#pragma once
#include <queue>
#include <stack>

template <class T>
class BinaryTree;

/*---------------声明BinaryTreeNode类--------------*/

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

/*-------------BinaryTreeNode 类中函数的具体实现------------*/

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

/*----------------二叉树类定义---------------------*/

template <class T>
class BinaryTree {
    private:
        BinaryTreeNode<T>* root;
    public:
        // 构造函数与析构函数
        BinaryTree();
        BinaryTree(BinaryTreeNode<T> *rt);
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

        // 定义遍历某结点时的操作
        void Visit(T value);


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


/*-------------二叉树类具体实现------------*/

// 构造与析构函数
template <class T>
BinaryTree<T>::BinaryTree() {}
template <class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *rt) {
    root = rt;
}
template <class T>
BinaryTree<T>::~BinaryTree() {
    DeleteBinaryTree(root);
}

// 判断树空
template <class T>
bool BinaryTree<T>::isEmpty() const {
    return this->root == NULL;
}

// 获取当前树的根结点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Root() {
    return this->root;
}

// 获取树中某结点的父结点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current) {
    using std::stack;
    stack< BinaryTreeNode<T>* > aStack;
    BinaryTreeNode<T> *pointer = this->root;
    if (root != NULL && current != NULL) {
        while (!aStack.empty() || pointer) {
            if (pointer != NULL) {
                // 如果pointer的孩子是current则返回parent
                if (current == pointer->left_child() || current == pointer->right_child) 
                    return pointer;
                aStack.push(pointer);
                pointer = pointer->left_child();
            } else {
                pointer = aStack.top();
                aStack.pop();
                pointer = pointer->right_child();
            }
        }
    }
}

// 获取树中某结点的左孩子
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* current) {
    return current->lchild;
}

// 获取树中某结点的右孩子
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* current) {
    return current->rchild;
}

// 构建树🌲
template <class T>
void BinaryTree<T>::CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree) {
    this->root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);
    // 将原来的两颗子树的根结点置为空，避免非法访问
    leftTree.root = rightTree.root = NULL; 
}

// 定义遍历某结点时的操作
template <class T>
void Visit(T value) {
    printf(value);
}

// 先序遍历，递归
template <class T>
void BinaryTree<T>::PreOrder(const BinaryTreeNode<T> *root) {
    if (root != NULL) {
        Visit(root->value());
        PreOrder(root->left_child());
        PreOrder(root->right_child());
    }
}

// 先序遍历，非递归
//TODO

// 中序遍历，递归
template <class T>
void BinaryTree<T>::InOrder(const BinaryTreeNode<T> *root) {
    if (root != NULL) {
        InOrder(root->left_child());
        Visit(root->value());
        InOrder(root->right_child());
    }
}

// 中序遍历，非递归
//TODO


// 后序遍历，递归
template <class T>
void BinaryTree<T>::PostOrder(const BinaryTreeNode<T> *root) {
    if (root != NULL) {
        PostOrder(root->left_child());
        PostOrder(root->right_child());
        Visit(root->value());
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
        if (pointer->left_child() != NULL) 
            aQueue.push(pointer->left_child());
        if (pointer->right_child() != NULL)
            aQueue.push(pointer->right_child());
    }
}

// 后序遍历删除二叉树
template <class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *root) {
    if (root != NULL) {
        DeleteBinaryTree(root->lchild);
        DeleteBinaryTree(root->rchild);
        delete root;
    }
}

/*--------------以下四个函数是求解main.cpp中作业题的关键函数----------------*/

// 获取叶节点个数
template <class T>
int BinaryTree<T>::GetLeafNumber() {
    if (this->root == NULL) return 0;
    if (this->root->isLeaf()) return 1;
    return GetLeafNumber(this->root->left_child()) + GetLeafNumber(this->root->right_child());
}

// 获取树高，空树高度为0
template <class T>
int BinaryTree<T>::GetTreeHeight(BinaryTreeNode<T> *root) {
    if (root == NULL) return 0;
    int lh = GetTreeHeight(root->left_child);
    int rh = GetTreeHeight(root->right_child);
    return lh > rh ? lh + 1 : rh + 1;
}

// 交换树中结点的左右孩子结点
template <class T>
void BinaryTree<T>::ReverseLR(BinaryTreeNode<T> *root) {
    BinaryTreeNode<T> *tmp;
    if (root != NULL) {
        tmp = root->left_child();
        root->left_child() = root->right_child();
        root->right_child() = tmp;
        ReverseLR(root->left_child());
        ReverseLR(root->right_child());
    }
}

// 求两个结点的公共最近祖先结点
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::NearestAncestor(BinaryTreeNode<T>* a, BinaryTreeNode<T>* b) {
    
}



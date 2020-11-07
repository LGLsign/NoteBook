#ifndef BST_H
#define BST_H

#include <iostream>

template<class Type> class BST;

template<class Type>
class BstNode {//树节点
    friend class BST<Type>;
public:
    void setData(const Type& x) {
        m_data = x;
    }
private:
    void display(int i);
    Type m_data;
    BstNode<Type>* m_LeftChild;
    BstNode<Type>* m_RightChild;
};

template<class Type>
class BST {
public:
    BST(BstNode<Type>* init = 0) {
        root = init;
    }

    bool Insert(const Type& x);
    BstNode<Type>* Search(const Type& x);
    BstNode<Type>* Search(BstNode<Type>*, const Type& x);
    BstNode<Type>* IterSearch(const Type& x);
    void display() {
        if (root) {
            root->display(1);
        }
        else {
            std::cout << "Tree is NULL!\n";
        }
    }
private:
    BstNode<Type>* root;
};

template<class Type>
void BstNode<Type>::display(int i) {
    std::cout << "Position: " << i << " data: " << m_data << "\n";
    if (m_LeftChild)  m_LeftChild->display(2*i);
    if (m_RightChild) m_RightChild->display(2*i+1);
}

template<class Type>
bool BST<Type>::Insert(const Type& x) {
    BstNode<Type> *cur = root;
    BstNode<Type> *pre = 0;  //pre指向cur的父结点
    while (cur) {
		pre = cur;
        if (x == cur->m_data) return false;   //重复值，返回错误
        if (x < cur->m_data) cur = cur->m_LeftChild;
        else if (x > cur->m_data) cur = cur->m_RightChild;
    }

    cur = new BstNode<Type>;
    cur->m_LeftChild = cur->m_RightChild = 0;
    cur->m_data = x;
    if (!root) root = cur;
	else if (x < pre->m_data) pre->m_LeftChild = cur;
	else pre->m_RightChild = cur;
	return true;
}

template<class Type>
BstNode<Type>* BST<Type>::Search(const Type& x) {
    return Search(root, x);
}

template<class Type>
BstNode<Type>* BST<Type>::Search(BstNode<Type>* root, const Type& x) {
	if (!root) return 0;
	if (x == root->m_data) return root;
	if (x < root->m_data) return Search(root->m_LeftChild, x);
	return Search(root->m_RightChild, x);
}

template<class Type>
BstNode<Type>* BST<Type>::IterSearch(const Type& x) {
	BstNode<Type> *cur = root;
	while(cur) {
		if (x == cur->m_data) return cur;
		if (x < cur->m_data) cur = cur->m_LeftChild;
		else cur = cur->m_RightChild;
	}
	return 0;
}

#endif

#include <iostream>
#include "BST.h"

int main() {
    
    BST<int> bst;

    bst.Insert(3);
    bst.Insert(9);
    bst.Insert(10);
    bst.Insert(19);
    bst.Insert(5);
    bst.Insert(8);

    bst.display();
    BstNode<int> *p = bst.IterSearch(9);
    if (0 == p)
        std::cout << "element is notfound!\n";
    else
        std::cout << "element was found!\n";
    
    return 0;
}

#include <iostream>
#include "Tree.h"

using Tree = mtr::Node<int>;

int stupid(Tree* tree, size_t target, size_t depth = 0) {
    if(!tree)
        return 0;

    else {
        int ris = stupid(tree->left(), target, depth + 1) +
                  stupid(tree->right(), target, depth + 1);
        
        if(tree->isLeaf() && depth == target)
            return tree->data() + ris;
        else
            return ris;
    }
}

int main() {
    Tree* tree;
    {
        tree = new Tree(1);
            tree->left() = new Tree(2);
                tree->left()->left() = new Tree(3);
                    tree->left()->left()->left() = new Tree(4);
                    tree->left()->left()->right() = new Tree(5);
                tree->left()->right() = new Tree(6);
            tree->right() = new Tree(7);
    }

    std::cout << stupid(tree, 2) << '\n';

    return 0;
}

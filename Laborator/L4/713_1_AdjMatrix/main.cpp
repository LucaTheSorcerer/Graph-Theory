#include "Graph.h"
#include <iostream>

int main() {
    // Example 1: binary tree
    Graph g1("../matrix1.txt");
    if (g1.isBinaryTree(g1)) {
        cout << "Graph is a binary tree" << endl;
    }
    else {
        cout << "Graph is not a binary tree" << endl;
    }
    cout << "In-order traversal: ";
    g1.printInorder(0);
    cout << endl;

    // Example 2: not a binary tree
    Graph g2("../matrix2.txt");
    if (g2.isBinaryTree(g2)) {
        cout << "Graph is a binary tree" << endl;
    }
    else {
        cout << "Graph is not a binary tree" << endl;
    }
    cout << "In-order traversal: ";
    g2.printInorder(0);
    cout << endl;

    return 0;
}
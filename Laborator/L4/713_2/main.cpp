#include "Graph.h"
#include <iostream>

int main() {
    // Example 1: binary tree
    Graph g("../matrix1.txt"); // create graph from input file
    if (!g.isBinaryTree(g)) { // check if graph is a binary tree
        cout << "Graph is a binary tree." << endl;
        vector<int> preorder;
        g.printPreorder(); // print preorder traversal of binary tree rooted at node 0
        cout << "Pre-order traversal: ";
        for (int i = 0; i < preorder.size(); i++) {
            cout << preorder[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Graph is not a binary tree." << endl;
    }
    return 0;

    return 0;
}
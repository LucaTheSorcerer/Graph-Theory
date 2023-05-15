#include "Graph.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <stack>

using namespace std;


Graph::Graph(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> V;
        adj.resize(V, vector<int>(V));
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                file >> adj[i][j];
            }
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
}

//bool Graph::isBinaryTree(const Graph& g) {
//    int num_of_edges = 0;
//    for (int i = 0; i < g.V; i++) {
//        for (int j = i + 1; j < g.V; j++) {
//            if (g.adj[i][j] == 1) {
//                num_of_edges++;
//            }
//        }
//    }
//    if (num_of_edges == g.V - 1) {
//        return true;
//    }
//    return false;
//}

//bool Graph::isBinaryTree(const Graph& g) {
//    int num_of_edges = 0;
//    int root = -1;
//    vector<int> childCount(g.V, 0);
//    vector<bool> visited(g.V, false);
//    vector<bool> stack(g.V, false);
//
//    // Check if the graph is acyclic using DFS
//    for (int i = 0; i < g.V; i++) {
//        if (!visited[i]) {
//            stack[i] = true;
//            visited[i] = true;
//
//            for (int j = 0; j < g.V; j++) {
//                if (g.adj[i][j] == 1) {
//                    if (stack[j]) {
//                        return false;
//                    }
//                    if (!visited[j]) {
//                        childCount[i]++;
//                        visited[j] = true;
//                        stack[j] = true;
//                    }
//                    else {
//                        return false;
//                    }
//                }
//            }
//
//            stack[i] = false;
//        }
//    }
//
//    // Check if the graph is connected
//    for (int i = 0; i < g.V; i++) {
//        if (childCount[i] == 0) {
//            if (root != -1) {
//                // More than one nodes with zero children, not a tree
//                return false;
//            }
//            root = i;
//        }
//        else if (childCount[i] > 2 && childCount[i] != g.V-1) {
//            // A node has more than two children, not a binary tree
//            return false;
//        }
//    }
//    if (root == -1) {
//        // No node with zero children found, not a tree
//        return false;
//    }
//
//    // Check if all edges are directed away from the root
//    visited.assign(g.V, false);
//    queue<int> q;
//    q.push(root);
//    visited[root] = true;
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        for (int v = 0; v < g.V; v++) {
//            if (g.adj[u][v] == 1) {
//                if (visited[v]) {
//                    // Edge is directed towards the root, not a tree
//                    return false;
//                }
//                visited[v] = true;
//                q.push(v);
//            }
//        }
//    }
//
//    // Check if the graph has n-1 edges
//    for (int i = 0; i < g.V; i++) {
//        for (int j = i + 1; j < g.V; j++) {
//            if (g.adj[i][j] == 1) {
//                num_of_edges++;
//            }
//        }
//    }
//    if (num_of_edges != g.V - 1) {
//        return false;
//    }
//
//    // If all conditions are satisfied, the graph is a binary tree
//    return true;
//}

bool Graph::isBinaryTree(const Graph& g) {
    int num_of_edges = 0;
    int root = -1;
    vector<int> childCount(g.V, 0);
    vector<bool> visited(g.V, false);

    // Check if the graph is acyclic using DFS
    for (int i = 0; i < g.V; i++) {
        if (!visited[i]) {
            visited[i] = true;

            for (int j = 0; j < g.V; j++) {
                if (g.adj[i][j] == 1) {
                    if (!visited[j]) {
                        childCount[i]++;
                        visited[j] = true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }

    // Check if the graph is connected
    for (int i = 0; i < g.V; i++) {
        if (childCount[i] == 0) {
            if (root != -1) {
                // More than one nodes with zero children, not a tree
                return false;
            }
            root = i;
        }
        else if (childCount[i] > 2) {
            // A node has more than two children, not a binary tree
            return false;
        }
    }
    if (root == -1) {
        // No node with zero children found, not a tree
        return false;
    }

    // Check if all edges are directed away from the root
    visited.assign(g.V, false);
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < g.V; v++) {
            if (g.adj[u][v] == 1) {
                if (visited[v]) {
                    // Edge is directed towards the root, not a tree
                    return false;
                }
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Check if the graph has n-1 edges
    for (int i = 0; i < g.V; i++) {
        for (int j = i + 1; j < g.V; j++) {
            if (g.adj[i][j] == 1) {
                num_of_edges++;
            }
        }
    }
    if (num_of_edges != g.V - 1) {
        return false;
    }

    // If all conditions are satisfied, the graph is a binary tree
    return true;
}

void Graph::printPreorder(int root, vector<bool>& visited) {
    visited[root] = true;
    cout << root << " ";  // Process the root node
    for (int i = 0; i < V; i++) {
        if (adj[root][i] == 1 && !visited[i]) {
            printPreorder(i, visited);  // Recursively process the left subtree
        }
    }
    for (int i = 0; i < V; i++) {
        if (adj[root][i] == 1 && !visited[i]) {
            printPreorder(i, visited);  // Recursively process the right subtree
        }
    }
}

// Wrapper function for preorder traversal starting from the root node
void Graph::printPreorder() {
    vector<bool> visited(V, false);
    printPreorder(0, visited);
}
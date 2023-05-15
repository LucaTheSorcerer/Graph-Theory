#include "Graph.h"

#include <iostream>
#include <fstream>
#include <vector>
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

bool Graph::isBinaryTree(const Graph& g) {
    int num_of_edges = 0;
    for (int i = 0; i < g.V; i++) {
        for (int j = i + 1; j < g.V; j++) {
            if (g.adj[i][j] == 1) {
                num_of_edges++;
            }
        }
    }
    if (num_of_edges == g.V - 1) {
        return true;
    }
    return false;
}

void Graph::printInorder(int node) {
    if (node >= V) {
        return;
    }
    printInorder(2*node + 1); // left child
    cout << node << " "; // node
    printInorder(2*node + 2); // right child
}

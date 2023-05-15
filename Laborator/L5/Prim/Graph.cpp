#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>
#include "Graph.h"


using namespace std;


Graph::Graph(const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> V;
        adj.resize(V, vector<int>(V, 0));
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                file >> adj[i][j];
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}


int Graph::minKey(const vector<int> &key, const vector<bool> &mstSet) {
    int minKey = INT_MAX;
    int minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void Graph::primMST() {
    vector<int> parent(V); // Array to store constructed MST
    vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet(V, false); // To represent set of vertices not yet included in MST

    // Start with the first vertex
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
        mstSet[u] = true; // Add the picked vertex to the MST set

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    printMST(parent, adj);
}

void Graph::printMST(const vector<int> &parent, const vector<vector<int>> &graph) {
    cout << "Edge\tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

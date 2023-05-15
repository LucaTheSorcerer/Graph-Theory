#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>
#include "Graph.h"


using namespace std;


Graph::Graph(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }

    file >> V;
    int u, v, weight;
    while (file >> u >> v >> weight) {
        edges.push_back({weight, {u, v}});
    }

    file.close();
}

int Graph::findSet(vector<int> &parent, int i) {
    if (parent[i] != i)
        parent[i] = findSet(parent, parent[i]);
    return parent[i];
}

void Graph::unionSet(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xroot = findSet(parent, x);
    int yroot = findSet(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Graph::kruskalMST() {
//    sort(edges.begin(), edges.end());
//
//    vector<pair<int, pair<int, int>>> mst;
//    vector<int> parent(V);
//    vector<int> rank(V, 0);
//
//    // Initialize parent vector and rank vector
//    for (int i = 0; i < V; i++)
//        parent[i] = i;
//
//    int mstWeight = 0;
//
//    // Process each edge in sorted order
//    for (auto edge : edges) {
//        int weight = edge.first;
//        int u = edge.second.first;
//        int v = edge.second.second;
//
//        int setU = findSet(parent, u);
//        int setV = findSet(parent, v);
//
//        if (setU != setV) {
//            mst.push_back({weight, {u, v}});
//            mstWeight += weight;
//            unionSet(parent, rank, setU, setV);
//        }
//    }
//
//    // Print minimum spanning tree
//    cout << "Minimum Spanning Tree:" << endl;
//    for (auto edge : mst) {
//        int u = edge.second.first;
//        int v = edge.second.second;
//        cout << u << " - " << v << endl;
//    }
//
//    cout << "Total Weight: " << mstWeight << endl;
    sort(edges.begin(), edges.end());

    vector<int> parent(V); // Parent array for union-find operations
    vector<int> rank(V, 0); // Rank array for union-by-rank

    // Initialize parent array and rank array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<pair<int, pair<int, int>>> mst; // Stores the MST

    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;

        int uRoot = findParent(parent, u);
        int vRoot = findParent(parent, v);

        // Check if including this edge forms a cycle
        if (uRoot != vRoot) {
            mst.push_back({weight, {u, v}});
            unionSet(parent, rank, uRoot, vRoot);
            totalCost += weight;
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:\n";
    for (auto edge : mst) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;
        cout << u << " -- " << v << " : " << weight << "\n";
    }

    cout << "Total Cost: " << totalCost << endl;
}


int Graph::findParent(vector<int>& parent, int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}
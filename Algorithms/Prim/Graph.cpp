#include "Graph.h"
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(const std::string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    file >> num_vertices;
    adj_matrix.resize(num_vertices, vector<int>(num_vertices));
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            file >> adj_matrix[i][j];
        }
    }
    file.close();
}

vector<int> Graph::prim() {
    vector<int> parent(num_vertices, -1);
    vector<bool> in_mst(num_vertices, false);
    vector<int> key(num_vertices, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);
    key[0] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        in_mst[u] = true;

        for(int vertex = 0; vertex < num_vertices; vertex++) {
            if(adj_matrix[u][vertex] != 0 && !in_mst[vertex] && adj_matrix[u][vertex] < key[vertex]) {
                parent[vertex] = u;
                key[vertex] = adj_matrix[u][vertex];
                pq.emplace(key[vertex], vertex);
            }
        }
    }
    return parent;
}
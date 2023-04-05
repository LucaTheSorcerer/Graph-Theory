#include "Graph.h"
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(const std::string &filename) {
    ifstream file(filename);
    file >> v;
    adj_list.resize(v);
    int source, destination;
    while(file >> source >> destination) {
        adj_list[source].push_back(destination);
        adj_list[destination].push_back(source);
    }
}

void Graph::BFS(int s) {
    vector<bool> visited(v, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int vertex: adj_list[u]) {
            if(!visited[vertex]) {
                visited[vertex] = true;
                q.push(vertex);
            }
        }
    }
}

//
// Created by Luca Tudor on 06.04.2023.
//
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph() = default;

Graph::Graph(const string &fileName) {
    ifstream file(fileName);

    if(!file.is_open()){
        cerr << "File not found" << endl;
        exit(1);
    }
    file >> nodes;
    file >> edges;
    adjacencyList.resize(nodes);

    for(int i = 0; i <  edges; i++){
        int node, connectedNode;
        file >> node >> connectedNode;
        adjacencyList[node].push_back(connectedNode);
        adjacencyList[connectedNode].push_back(node);
    }

    file.close();
}

Graph::Graph(const Graph &other) {
    nodes = other.nodes;
    edges = other.edges;
    adjacencyList = other.adjacencyList;
}

void Graph::text() {
    for(int i = 0; i < nodes; i++){
        cout << i << ": ";
        for(int j : adjacencyList[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::BFS(int start) {
    vector<bool> visited(nodes, false);
    queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while(!queue.empty()){
        int node = queue.front();
        queue.pop();
        cout << node << " ";

        for(int i : adjacencyList[node]){
            if(!visited[i]){
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    cout << endl;
}

//Implement a method void away(int start, int stop), which shows a path of minimum length with the help of width search between start and stop and displays it on the screen. If such a Way does not exist, as the message "no way" written on the screen.
int Graph::weg(int start, int stop) const {
    vector<bool> visited(nodes, false);
    vector<int> distance(nodes, -1);
    vector<int> parent(nodes, -1);

    queue<int> q;
    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int v : adjacencyList[node]) {
            if(!visited[v]) {
                visited[v] = true;
                distance[v] = distance[node] + 1;
                parent[v] = node;
                q.push(v);

                if(v == stop) {
                    cout << "The shortest path is: ";
                    int current = v;
                    while(current != -1) {
                        cout << current << " ";
                        current = parent[current];
                    }
                    cout << endl;
                    return distance[v];
                }
            }
        }
    }
    cout << "Kein weg" << endl;
    return -1;
}
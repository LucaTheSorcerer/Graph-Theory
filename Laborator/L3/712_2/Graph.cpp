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

int Graph::weg(int start, int stop) {
    vector<bool> visited(nodes, false);
    vector<int> distance(nodes, 0);
    queue<int> queue;

    visited[start] = true;
    distance[start] = 0;
    queue.push(start);

    while(!queue.empty()){
        int node = queue.front();
        queue.pop();

        for(auto i : adjacencyList[node]){
            if(!visited[i]){
                distance[i] = distance[node] + 1;
                visited[i] = true;
                if(i == stop){
                    cout << "Way between " << start << " and " << stop << ": " << distance[i] << endl;
                    return distance[i];
                }
                queue.push(i);
            }
        }
    }
    cout << endl;

    cout << "No way between " << start << " and " << stop << endl;
    return -1;
}
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>
#include <unordered_map>
#include "Graph.h"


using namespace std;


Graph::Graph(const string &filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    int maxVertexId = -1;
    string source, destination;
    int weight;
    while (inputFile >> source >> destination >> weight) {
        int srcId = getVertexId(source);
        int destId = getVertexId(destination);
        maxVertexId = max(maxVertexId, max(srcId, destId));

        if (srcId >= adjacencyList.size())
            adjacencyList.resize(srcId + 1);

        if (destId >= adjacencyList.size())
            adjacencyList.resize(destId + 1);

        adjacencyList[srcId].emplace_back(srcId, destId, weight);
        adjacencyList[destId].emplace_back(destId, srcId, weight);
    }

    numVertices = maxVertexId + 1;
    inputFile.close();
}


void Graph::primMST() {
    vector<bool> visited(numVertices, false);
    priority_queue<Edge, vector<Edge>, function<bool(const Edge&, const Edge&)>> minHeap([](const Edge& a, const Edge& b) {
        return a.weight > b.weight; // Min-Heap based on edge weights
    });

    int startVertex = 0; // Choose starting vertex as 0
    visited[startVertex] = true;

    for (const Edge& edge : adjacencyList[startVertex])
        minHeap.push(edge);

    cout << "Minimum Spanning Tree (MST):\n";
    int mstWeight = 0;
    while (!minHeap.empty()) {
        Edge currentEdge = minHeap.top();
        minHeap.pop();

        if (visited[currentEdge.destination])
            continue;

        visited[currentEdge.destination] = true;
        mstWeight += currentEdge.weight;
        cout << getCityName(currentEdge.source) << " - " << getCityName(currentEdge.destination)
             << "  " << currentEdge.weight << endl;

        for (const Edge& edge : adjacencyList[currentEdge.destination]) {
            if (!visited[edge.destination])
                minHeap.push(edge);
        }
    }

    cout << "Total MST weight: " << mstWeight << endl;
}

int Graph::getVertexId(const string &cityName) {
    static unordered_map<string, int> vertexIds;
    static int nextId = 0;

    auto it = vertexIds.find(cityName);
    if (it != vertexIds.end())
        return it->second;

    vertexIds[cityName] = nextId;
    return nextId++;
}

string Graph::getCityName(int vertexId) {
    static unordered_map<int, string> cityNames;

    auto it = cityNames.find(vertexId);
    if (it != cityNames.end())
        return it->second;

    return "City" + to_string(vertexId);
}




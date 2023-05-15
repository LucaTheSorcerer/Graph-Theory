#pragma once

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
        file >> numVertices;
        int numEdges;
        file >> numEdges;
        for (int i = 0; i < numEdges; i++) {
            Edge edge{};
            file >> edge.source >> edge.destination >> edge.weight;
            edges.push_back(edge);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

vector<int> Graph::bellmanFord(int source) {
    vector<int> distances(numVertices, numeric_limits<int>::max());
    distances[source] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
            cerr << "Graph contains a negative-weight cycle!" << endl;
            return {};
        }
    }

    return distances;
}

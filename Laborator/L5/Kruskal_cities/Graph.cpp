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
        cerr << "Error opening file: " << filename << endl;
        return;
    }


    string city1, city2;
    int weight;
    while (inputFile >> city1 >> city2 >> weight) {
        edges.emplace_back(city1, city2, weight);
    }

    inputFile.close();
}

int Graph::vertexIndex(const string &city) {
    // Assign an integer index to each city
    static unordered_map<string, int> cityIndices;
    static int currentIndex = 0;

    auto it = cityIndices.find(city);
    if (it != cityIndices.end()) {
        return it->second;
    } else {
        cityIndices[city] = currentIndex;
        return currentIndex++;
    }
}

int Graph::findRoot(vector<int> &parent, int vertex) {
    while (vertex != parent[vertex]) {
        parent[vertex] = parent[parent[vertex]];
        vertex = parent[vertex];
    }
    return vertex;
}

void Graph::unionVertices(vector<int> &parent, int root1, int root2) {
    parent[root2] = root1;
}

void Graph::addEdge(const string &city1, const string &city2, int weight) {
    edges.emplace_back(city1, city2, weight);
}

vector<Edge> Graph::findMinimumSpanningTree() {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<int> parent(numVertices);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    vector<Edge> minimumSpanningTree;
    int numEdges = 0;

    for (const Edge& edge : edges) {
        int root1 = findRoot(parent, vertexIndex(edge.city1));
        int root2 = findRoot(parent, vertexIndex(edge.city2));

        if (root1 != root2) {
            minimumSpanningTree.push_back(edge);
            unionVertices(parent, root1, root2);
            numEdges++;

            totalCost += edge.weight;

            if (numEdges == numVertices - 1) {
                break;  // Minimum spanning tree found
            }
        }
    }

    return minimumSpanningTree;
}

int Graph::getTotalCost() const {
    return totalCost;
}



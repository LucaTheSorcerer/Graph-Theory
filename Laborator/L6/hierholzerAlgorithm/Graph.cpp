#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>
#include <unordered_map>
#include "Graph.h"


using namespace std;


/**
 * This is the constructor of the Graph class, which takes a filename as a parameter.
 * It reads the graph data from the specified file and constructs the graph using an adjacency list representation.
 * @param filename
 */
Graph::Graph(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string city1, city2;

    while (file >> city1 >> city2) {
        adjacencyList[city1].push_back(city2);
        adjacencyList[city2].push_back(city1);
    }

    file.close();
}

void Graph::removeEdge(const string &src, const string &dest) {
    vector<string>& srcNeighbors = adjacencyList[src];
    vector<string>& destNeighbors = adjacencyList[dest];

    auto srcIt = find(srcNeighbors.begin(), srcNeighbors.end(), dest);
    if (srcIt != srcNeighbors.end())
        srcNeighbors.erase(srcIt);

    auto destIt = find(destNeighbors.begin(), destNeighbors.end(), src);
    if (destIt != destNeighbors.end())
        destNeighbors.erase(destIt);
}

vector<string> Graph::findEulerianPath() {
    vector<string> eulerianPath;

    if (adjacencyList.empty()) {
        return eulerianPath;  // Empty graph
    }

    for (const auto& entry : adjacencyList) {
        const string& startVertex = entry.first;

        // Stack to store the current tour/circuit
        stack<string> tour;
        tour.push(startVertex);

        while (!tour.empty()) {
            string currentVertex = tour.top();

            if (adjacencyList[currentVertex].empty()) {
                // If there are no unused edges from the current vertex, add it to the Eulerian path
                eulerianPath.push_back(currentVertex);
                tour.pop();
            }
            else {
                // Follow an unused edge to a neighboring vertex
                string nextVertex = adjacencyList[currentVertex].back();

                // Remove the edge from the graph
                removeEdge(currentVertex, nextVertex);

                // Set the destination vertex as the new current vertex
                tour.push(nextVertex);
            }
        }
    }

    // Reverse the Eulerian path to obtain the correct order
    reverse(eulerianPath.begin(), eulerianPath.end());

    return eulerianPath;
}

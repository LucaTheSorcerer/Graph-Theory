//#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <limits>

using namespace std;

class Graph {
private:
    map<string, map<string, int>> adjacencyList;

public:
    Graph(const string& filename) {
        ifstream file(filename);
        string city1, city2;
        int weight;


        while (file >> city1 >> city2 >> weight) {
            adjacencyList[city1][city2] = weight;
            adjacencyList[city2][city1] = weight;  // Add reverse edge
        }

        file.close();
    }

    void BellmanFord(const string& source, const string& destination) {
        // Step 1: Initialize distances and predecessors
        map<string, int> distance;
        map<string, string> predecessor;
        for (const auto& pair : adjacencyList) {
            distance[pair.first] = numeric_limits<int>::max();
            predecessor[pair.first] = "";
        }
        distance[source] = 0;

        // Step 2: Relax edges repeatedly
        for (size_t i = 0; i < adjacencyList.size() - 1; ++i) {
            for (const auto& pair : adjacencyList) {
                const string& u = pair.first;
                for (const auto& neighbor : adjacencyList[u]) {
                    const string& v = neighbor.first;
                    int weight = neighbor.second;
                    if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                        predecessor[v] = u;
                    }
                }
            }
        }

        // Step 3: Check for negative-weight cycles
        for (const auto& pair : adjacencyList) {
            const string& u = pair.first;
            for (const auto& neighbor : adjacencyList[u]) {
                const string& v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                    cout << "Negative-weight cycle detected!" << endl;
                    return;
                }
            }
        }

        // Step 4: Print the shortest path
        PrintShortestPath(source, destination, distance, predecessor);
    }

    void PrintShortestPath(const string& source, const string& destination,
                           const map<string, int>& distance, const map<string, string>& predecessor) {
        if (distance.at(destination) == numeric_limits<int>::max()) {
            cout << "There is no path between " << source << " and " << destination << endl;
            return;
        }

        vector<string> path;
        string current = destination;
        while (current != "") {
            path.push_back(current);
            current = predecessor.at(current);
        }
        reverse(path.begin(), path.end());

        cout << "Shortest path from " << source << " to " << destination << ": ";
        for (const string& city : path) {
            cout << city;
            if (city != destination) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Total distance: " << distance.at(destination) << endl;
    }
};

int main() {
    Graph graph("../Graph.txt");

    // Find the shortest path from "Sibiu" to "Constanta"
    graph.BellmanFord("Sibiu", "Constanta");

    return 0;
}



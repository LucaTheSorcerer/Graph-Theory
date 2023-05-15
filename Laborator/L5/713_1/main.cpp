#include <iostream>
#include <fstream>

#include "Graph.h"


int main() {
    Graph graph("../bellman_ford.txt");  // Assuming the graph data is stored in a file named "graph.txt"

    int source = 0;
    vector<int> distances = graph.bellmanFord(source);

    if (!distances.empty()) {
        cout << "Shortest distances from vertex " << source << ":" << endl;
        for (int i = 0; i < distances.size(); i++) {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }

    return 0;
}


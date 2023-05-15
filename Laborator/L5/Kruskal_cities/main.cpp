#include <iostream>

#include "Graph.h"

int main() {
    Graph graph("../kruskal_cities.txt"); // Provide the filename with city weights

    vector<Edge> minimumSpanningTree = graph.findMinimumSpanningTree();

    cout << "Minimum Spanning Tree:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.city1 << " -- " << edge.city2 << " : " << edge.weight << endl;
    }

    cout << "Total cost: " << graph.getTotalCost() << endl;
    return 0;
}

#include <iostream>

#include "Graph.h"

int main() {
    // Create a Graph object by providing the filename
    Graph graph("../Land2.txt");

    // Find the Eulerian path/circuit
    vector<string> eulerianPath = graph.findEulerianPath();

    // Print the Eulerian path/circuit
    cout << "Eulerian Path/Circuit: ";
    for (const string& city : eulerianPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}


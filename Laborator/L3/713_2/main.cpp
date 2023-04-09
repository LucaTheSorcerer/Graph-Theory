#include "Graph.h"
#include <iostream>

int main() {
    // Graph from file graph1.txt
    Graph g("../graph.txt");

    // BFS for node 0
    cout << "BFS starting from node 0: ";
    g.BFS(0);
    cout << endl;

    // Components of the graph
    g.printConexComponent(g);

    return 0;
}

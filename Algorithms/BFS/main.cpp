#include <iostream>
#include "Graph.h"

int main() {
    Graph g("../small_graph.in");

    cout << "BFS traversal: ";
    g.BFS(0);
    cout << endl;

    return 0;
}

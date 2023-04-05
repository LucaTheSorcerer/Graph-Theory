#include <iostream>
#include "Graph.h"

int main() {
    Graph g("../small_graph.in");

    cout << "DFS traversal: ";
    g.DFS(0);
    cout << endl;

    return 0;
}

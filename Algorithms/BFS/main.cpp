#include <iostream>
#include "Graph.h"

int main() {
    Graph g("../1m.txt");

    cout << "BFS traversal: ";
    g.BFS(0);
    cout << endl;

    return 0;
}

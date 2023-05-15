#include <iostream>

#include "Graph.h"

int main() {
    Graph graph("../kruskal.txt");
    graph.kruskalMST();

    return 0;
}


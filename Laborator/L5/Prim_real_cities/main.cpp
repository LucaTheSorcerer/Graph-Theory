#include <iostream>

#include "Graph.h"

int main() {
    Graph graph("../Graph.txt");
    graph.primMST();

    return 0;
}

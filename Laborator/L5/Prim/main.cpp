#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "Graph.h"

int main() {
    std::string filename = "../prim.txt"; // Replace with your graph data file name
    Graph graph(filename);
    graph.primMST();
    return 0;
}


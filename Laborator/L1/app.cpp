#include "Graph.h"
#include<iostream>
#include<fstream>

using namespace std;

int main() {
    Graph g;
    cout << g.isEdge(0, 1) << endl;
    g.printGraph();
    g.printAdjList(); // added line to print adjacency lists
    cout << "The minimum degree of the graph is: " << g.minDegree() << endl;
    cout << "The maximum degree of the graph is: " << g.maxDegree() << endl;
    return 0;
}

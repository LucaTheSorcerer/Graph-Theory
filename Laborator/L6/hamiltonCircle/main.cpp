#include <iostream>

#include "Graph.h"

int main() {
    string filename = "../Land.txt";
    Graph graph(filename);

    if (graph.isHamiltonianGraph())
        cout << "The graph is a Hamiltonian graph." << endl;
    else
        cout << "The graph is not a Hamiltonian graph." << endl;

    return 0;
}

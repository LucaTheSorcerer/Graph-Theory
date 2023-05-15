#include "Graph.h"
#include <iostream>

int main() {
    // Graph from file graph1.txt
    Graph g("../matrix1.txt");


    int num_components = g.AnzahlKomponente(); // Compute the number of connected components
    int num_trees = g.AnzahlBaeume(); // Compute the number of trees in the graph

    cout << "Number of components: " << num_components << endl;
    cout << "Number of trees: " << num_trees << endl;


    return 0;
}

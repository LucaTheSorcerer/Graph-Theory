#include <iostream>
#include "Graph.h"

int main() {
    Graph g("../prim.in");

    vector<int> parent = g.prim();

    cout << "Minimum Spanning Tree: \n";

    for(int i = 1; i < parent.size(); i++) {
        cout << parent[i] << " - " << i << endl;
    }
    return 0;
}

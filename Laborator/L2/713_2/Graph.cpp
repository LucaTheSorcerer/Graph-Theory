#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph() : n(0), adj_matrix(0) {}

Graph::Graph(const string& filename) {
    ifstream file(filename);
    if(!file) {
        cerr << "Cannot open the file" << filename << endl;
        return;
    }

    file >> n;
    adj_matrix.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            file >> adj_matrix[i][j];
        }
    }

    file.close();
}

Graph::Graph(const Graph &g) {
    n = g.n;
    adj_matrix = g.adj_matrix;
    adj_matrix.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj_matrix[i][j] = g.adj_matrix[i][j];
        }
    }
}



void Graph::printPfad(int x, int y) {
    bool found_path = false;
    for (int i = 0; i < n; i++) {
        if (adj_matrix[x][i] == 1 && adj_matrix[i][y] == 1) {
            std::cout << x << " goes to " << i << " goes to " << y << std::endl;
            found_path = true;
        }
    }

    if (!found_path) {
        std::cout << "A path of length two does not exist in the given adjacency matrix" << std::endl;
    }
}
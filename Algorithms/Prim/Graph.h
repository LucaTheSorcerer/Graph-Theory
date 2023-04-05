#pragma once

#include <vector>
#include <string>


using namespace std;

class Graph {
private:
    vector<vector<int>> adj_matrix;
    int num_vertices;

public:
    explicit Graph(const string& filename);
    vector<int> prim();
};



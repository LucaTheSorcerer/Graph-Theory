#pragma once

#include <vector>
#include <string>


using namespace std;

class Graph {
private:
    int n{};
    vector<vector<int>> adj_matrix;

public:
    Graph();
    explicit Graph(const string& filename);
    Graph(const Graph& g);
    void printPfad(int x, int y);
};



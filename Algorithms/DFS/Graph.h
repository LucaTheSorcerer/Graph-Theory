#pragma once

#include <vector>
#include <string>


using namespace std;

class Graph {
private:
    int v; //Number of vertices
    vector<vector<int>> adj_list; //adj list to store the edges

public:
    Graph();
    explicit Graph(const string& filename);
    void DFS(int s);
};



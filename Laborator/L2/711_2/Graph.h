#pragma once

#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    int n{};
    int m{};
    vector<pair<int, int>> edge_list{};
    vector<vector<int>> adj_list{};

public:
    Graph();
    Graph(const string& filename);
    Graph(const Graph &g);
    Graph& operator=(const Graph& g);
    ~Graph();

    void add_node();
    void add_edge(int u, int v);
    bool has_edge(int u, int v) const;
    Graph intersection(const Graph& g) const;
    void write_to_file(const string& filename) const;

};



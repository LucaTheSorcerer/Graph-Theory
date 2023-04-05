#pragma once

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits> // For INT_MAX
#include <fstream>

using namespace std;


template<typename T>
class Graph {
private:
    unordered_map<T, vector<pair<T, int>>> adj_list;

public:
    explicit Graph(const string& filename);
    void add_edge(T source, T destination, int weight);
    void dijkstra(T source);
};




/**
 _____________________________________________________________________________________________________
/ @Author: Luca Tudor, group 713, Faculty of Computer Science                                         \
| **************************************************************************************************** |
| BFS for an undirected graph and components                                                           |
| **************************************************************************************************** |
| Methods:                                                                                             |
\ 1. BFS(int x) - Breadth First Search for a graph starting from node x                                /
 ------------------------------------------------------------------------------------------------------
  \
   \   \_\_    _/_/
    \      \__/
           (oo)\_______
           (__)\       )\/\
               ||----w |
               ||     ||
*/

#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    string city1;
    string city2;
    int weight;

    Edge(const string& c1, const string& c2, int w) : city1(c1), city2(c2), weight(w) {}
};
class Graph {
private:
    vector<Edge> edges;
    int numVertices{};
    int totalCost = 0;

    int vertexIndex(const string& city);
    int findRoot(vector<int>& parent, int vertex);
    void unionVertices(vector<int>& parent, int root1, int root2);

public:
    // Constructors
    Graph() : numVertices(0) {}
    explicit Graph(const string& filename);
    void addEdge(const string& city1, const string& city2, int weight);
    vector<Edge> findMinimumSpanningTree();
    int getTotalCost() const;

};


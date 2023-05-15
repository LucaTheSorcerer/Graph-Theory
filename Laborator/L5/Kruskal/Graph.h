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


class Graph {
private:
    int V;  // Number of vertices
    vector<pair<int, pair<int, int>>> edges;  // Graph edges
    int totalCost = 0;

public:
    // Constructors
    explicit Graph(const string& filename);
    int findSet(vector<int>& parent, int i);
    void unionSet(vector<int>& parent, vector<int>& rank, int x, int y);
    void kruskalMST();

    int findParent(vector<int> &parent, int node);
};


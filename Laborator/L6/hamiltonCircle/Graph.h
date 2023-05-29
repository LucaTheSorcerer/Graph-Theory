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
    int V;  // number of vertices
    vector<vector<int>> adjacencyMatrix;
    vector<string> cities;

public:
    // Constructors
    explicit Graph(const string& filename);
    void addEdge(const string& city1, const string& city2);
    int getIndex(const string& city);
    bool isHamiltonianGraph();
    bool isHamiltonianUtil(vector<int>& path, vector<bool>& visited, int count);
};


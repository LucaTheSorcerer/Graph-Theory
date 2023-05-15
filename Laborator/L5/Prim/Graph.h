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
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency matrix

public:
    // Constructors
    explicit Graph(const string& filename);

    int minKey(const vector<int>& key, const vector<bool>& mstSet);
    void printMST(const vector<int>& parent, const vector<vector<int>>& graph);
    void primMST();

};


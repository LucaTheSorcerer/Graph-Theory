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
    //Number of nodes
    vector<vector<int>> adjacency_matrix;
    int num_nodes;

public:
    // Constructors
    Graph(const string& fileName);

    // Methods
    void DFS(int node, vector<bool>& visited);
    int AnzahlKomponente();
    int AnzahlBaeume();

};


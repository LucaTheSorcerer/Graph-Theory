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
    int E;  // number of edges
    vector<vector<int>> adjList;  // adjacency list

public:
    // Constructors
    Graph(const string& fileName);

    // Methods
    void DFSUtil(int v, vector<bool>& visited);
    int AnzahlKomponente();
    int AnzahlBaeume();

};


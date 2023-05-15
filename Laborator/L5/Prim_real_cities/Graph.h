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
#include <unordered_map>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};


class Graph {
private:
    int numVertices;
    unordered_map<string, vector<pair<string, int>>> adjacencyList;
    unordered_map<string, bool> visited;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;


    int getVertexId(const string& vertex);
    string getVertexName(int index);

public:
    // Constructors
    explicit Graph(const string& filename);

    void primMST();

};


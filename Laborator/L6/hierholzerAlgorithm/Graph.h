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
#include <stack>

using namespace std;


class Graph {
private:
    unordered_map<string, vector<string>> adjacencyList;

public:
    // Constructors
    explicit Graph(const string& filename);
    void removeEdge(const string& src, const string& dest);
    vector<string> findEulerianPath();

};


/**
 _____________________________________________________________________________________________________
/ @Author: Luca Tudor, group 713, Faculty of Computer Science                                         \
| **************************************************************************************************** |
| BFS for an undirected graph and components                                                           |
| **************************************************************************************************** |
| Methods:                                                                                             |
|     - getIndexOfElement                                                                              |
|     - setElementName                                                                                 |
|     - addLink                                                                                        |
|     - deleteLink                                                                                     |
|      - hasLink                                                                                       |
|      - linkWeight                                                                                    |
|      - hasElement                                                                                    |
|      - countToLinks                                                                                  |
|      - countFromLinks                                                                                |
\      - countAllLinks                                                                                 /
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
    int size;

    //Adjacency matrix
    vector<vector<int>> adjacencyMatrix; // Adjazenzmatrix

public:
    // Constructors
    Graph();
    Graph(int size);
    Graph(const string& fileName);

    // Methods
    void BFS(int x);
    void printConexComponent(Graph g);
};


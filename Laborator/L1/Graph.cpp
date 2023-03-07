#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph() {
    ifstream f;
    f.open("../data.in");
    f >> n;
    f >> m;
    int x, y;
    adjList.resize(n, vector<int>()); //rezises the adjacency list vector to have n elements
                                                 //where each element in an empty vector<int>
                                                 //empty vector<int> for each new element
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        addEdge(x, y);
    }
}

void Graph::addEdge(int x, int y) {
    matrix[x][y] = 1;
    matrix[y][x] = 1;
    adjList[x].push_back(y); // update adjacency lists
    adjList[y].push_back(x);
}

bool Graph::isEdge(int x, int y) {
    return matrix[x][y] == 1;
}

void Graph::printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::minDegree() {
    int minimum = n;
    int i;
    for(i = 0; i < n; i++)
    {
        int degree = adjList[i].size();
        if (degree < minimum)
        {
            minimum = degree;
        }
    }
    return minimum;
}

int Graph::maxDegree() {
    int maximum = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        int degree = adjList[i].size();
        if(degree > maximum)
        {
            maximum = degree;
        }
    }
    return maximum;
}

void Graph::printAdjList() {
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

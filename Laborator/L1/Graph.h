#include <vector>
#include <iostream>
#include <fstream>

class Graph {
private:
    int n;
    int m;
    int matrix[100][100];
    std::vector<std::vector<int>> adjList; // added data member for adjacency lists
    /*
     * Above we declare a vector of vectors of integers. It creates a dynamic two-dimensional array where each row is a
     * vector and the entire array is represented by a vector of those vectors
     */
public:
    Graph();
    void addEdge(int x, int y);
    bool isEdge(int x, int y);
    void printGraph();
    void printAdjList(); // added method to print adjacency lists
    int minDegree();
    int maxDegree();
};

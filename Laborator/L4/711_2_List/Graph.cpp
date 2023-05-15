#include "Graph.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


// Constructor that reads adjacency matrix from file
Graph::Graph(const string& fileName) {
    ifstream file(fileName);
    file >> V >> E;
    adjList.resize(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        file >> u >> v;
        u--;  // adjust to 0-based indexing
        v--;  // adjust to 0-based indexing
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    file.close();
}

// Depth-first search for counting connected components
void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;

    // recursively traverse all adjacent vertices
    for (int i = 0; i < adjList[v].size(); i++) {
        int u = adjList[v][i];
        if (!visited[u]) {
            DFSUtil(u, visited);
        }
    }
}

//// Method to count the number of connected components
//int Graph::AnzahlKomponente() {
//    vector<bool> visited(V, false);
//    int count = 0;
//    for (int v = 0; v < V; v++) {
//        if (!visited[v]) {
//            DFSUtil(v, visited);
//            count++;
//        }
//    }
//    return count;
//}

int Graph::AnzahlKomponente()
{

    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // To store the number of connected components
    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            count += 1;
        }
    }

    return count;
}

// method to determine the number of trees in the graph
int Graph::AnzahlBaeume() {
    vector<bool> visited(V, false);
    int count = 0;
    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            // count connected components with DFS
            DFSUtil(v, visited);

            // check if it is a tree
            int edges = 0;
            for (int i = 0; i < V; i++) {
                edges += adjList[i].size();
            }
            edges /= 2;  // each edge is counted twice
            if (edges == V - 1) {
                count++;
            }
        }
    }
    return count;
}




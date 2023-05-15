#include "Graph.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


// Constructor that reads adjacency matrix from file
Graph::Graph(const std::string &fileName)  {
    ifstream infile(fileName);
    infile >> num_nodes;
    adjacency_matrix.resize(num_nodes, vector<int>(num_nodes));
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            infile >> adjacency_matrix[i][j];
        }
    }
    infile.close();
}

// Depth-first search for counting connected components
void Graph::DFS(int node, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < num_nodes; i++) {
        if (adjacency_matrix[node][i] && !visited[i]) {
            DFS(i, visited);
        }
    }
}

// Method to count the number of connected components
int Graph::AnzahlKomponente() {
    vector<bool> visited(num_nodes, false);
    int count = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            DFS(i, visited);
            count++;
        }
    }
    return count;
}

// method to determine the number of trees in the graph
int Graph::AnzahlBaeume() {
    vector<bool> visited(num_nodes, false);
    int count = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            stack<int> s;
            s.push(i);
            while (!s.empty()) {
                int v = s.top();
                s.pop();
                visited[v] = true;
                int neighbor_count = 0;
                for (int j = 0; j < num_nodes; j++) {
                    if (adjacency_matrix[v][j] && !visited[j]) {
                        neighbor_count++;
                        s.push(j);
                    }
                }
                if (neighbor_count > 1) {
                    // this component has more than one neighbor, so it's not a tree
                    break;
                }
            }
            if (s.empty()) {
                // the stack is empty, so all vertices were visited and the component is a tree
                count++;
            }
        }
    }
    return count;
}



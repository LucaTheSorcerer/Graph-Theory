#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>
#include <unordered_map>
#include "Graph.h"


using namespace std;


/**
 * @brief This is the constructor of the Graph class. It takes a filename as input and reads the graph data from the
 * file.
   @details Steps:
        Open the file using the provided filename.
        Check if the file was successfully opened. If not, display an error message and return.
        Read the city names (city1 and city2) from the file.
        Call the addEdge function to add an edge between the two cities.
        Repeat steps 3 and 4 until all edges in the file have been processed.
        Close the file.
 * @param filename
 */
Graph::Graph(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Read the graph data from the file
    string city1, city2;
    while (file >> city1 >> city2) {
        addEdge(city1, city2);
    }
    file.close();
}

/**
 * @brief This function adds an edge between two cities in the graph's adjacency matrix.
   @details Steps:
        Get the indices of city1 and city2 using the getIndex function.
        Resize the adjacency matrix if either index is greater than or equal to the current size.
        Set the weight of the edge in the adjacency matrix by updating the corresponding entries.
 * @param city1
 * @param city2
 */
void Graph::addEdge(const string &city1, const string &city2) {
    int index1 = getIndex(city1);
    int index2 = getIndex(city2);

    // Resize the adjacency matrix if needed
    if (index1 >= V) {
        V = index1 + 1;
        adjacencyMatrix.resize(V, vector<int>(V, 0));
    }
    if (index2 >= V) {
        V = index2 + 1;
        adjacencyMatrix.resize(V, vector<int>(V, 0));
    }

    // Set the weight in the adjacency matrix
    adjacencyMatrix[index1][index2] = 1;
    adjacencyMatrix[index2][index1] = 1;
}

/**
 * @briefThis function returns the index of a city in the adjacency matrix. If the city is not found, it adds it to the
 * list of cities and returns the new index.
   @details Steps:
        Iterate over the list of cities.
        If the current city matches the input city, return its index.
        If the input city is not found, add it to the list of cities, update the size (V), and return the new index.
 * @param city
 * @return
 */
int Graph::getIndex(const string &city) {
    for (int i = 0; i < V; i++) {
        // City names are assumed to be unique
        if (cities[i] == city)
            return i;
    }
    cities.push_back(city);
    return V;
}

/**
 * @brief This function checks whether the graph contains a Hamiltonian cycle (a path that visits every vertex exactly
 * once and ends at the starting vertex).
   @details Steps:
        Create an empty path vector to store the current Hamiltonian path.
        Create a visited vector initialized with false for all vertices.
        Start the path from the first city (index 0) and add it to the path vector.
        Call the isHamiltonianUtil function with the path, visited, and count = 1 (indicating the first city has been
        visited).
        If the isHamiltonianUtil function returns true, a Hamiltonian cycle exists in the graph, so return true.
        Otherwise, return false.
 * @return
 */
bool Graph::isHamiltonianGraph() {
    vector<int> path;
    vector<bool> visited(V, false);
    path.push_back(0);  // Start from the first city

    if (isHamiltonianUtil(path, visited, 1))
        return true;

    return false;
}

/**
 * @brief This is a recursive utility function used by isHamiltonianGraph to perform a depth-first search for finding
 * a Hamiltonian path or cycle.
    Steps:
        If the count equals the number of vertices (count == V), all cities have been visited.
        Check if the last city in the path has an edge to the first city, forming a Hamiltonian cycle. If so,
        return true.
        Iterate over all vertices (cities) except the first one (v = 1 to V-1).
        Check if the current vertex (v) has not been visited and there is an edge between the last city in the path
        and the current vertex.
        If the conditions in step 4 are satisfied, mark the current vertex as visited, add it to the path, and
        increment the count.
        Recursively call the isHamiltonianUtil function with the updated path, visited, and count.
        If the recursive call in step 6 returns true, a Hamiltonian path or cycle has been found, so return true.
        If the recursive call returns false, backtrack by marking the current vertex as unvisited, removing it from
        the path, and continuing to the next vertex.
        If no Hamiltonian path or cycle is found after checking all vertices, return false.
 * @param path
 * @param visited
 * @param count
 * @return
 */
bool Graph::isHamiltonianUtil(vector<int> &path, vector<bool> &visited, int count) {
    if (count == V) {
        // All cities have been visited
        int lastCity = path.back();
        int firstCity = path.front();
        if (adjacencyMatrix[lastCity][firstCity] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (!visited[v] && adjacencyMatrix[path.back()][v] == 1) {
            visited[v] = true;
            path.push_back(v);

            if (isHamiltonianUtil(path, visited, count + 1))
                return true;

            visited[v] = false;
            path.pop_back();
        }
    }

    return false;
}

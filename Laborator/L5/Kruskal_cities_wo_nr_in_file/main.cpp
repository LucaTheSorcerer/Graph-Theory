/**
 _____________________________________________________________________________________________________
/ @Author: Luca Tudor, group 713, Faculty of Computer Science                                         \
| **************************************************************************************************** |
| Kruskal algorithm implementation                                                                     |
| **************************************************************************************************** |
| Methods:                                                                                             |
|     - Graph(filename)                                                                                |
|     - int findSet(parent, int i)                                                                     |
|     - unionSets(parent, rank,i, j)                                                                   |
|     - void kruskalMST()                                                                              |
\     - bool isConex()                                                                                 /
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
    struct Edge {
        string src;
        string dest;
        int weight;

        Edge(const string& s, const string& d, int w) : src(s), dest(d), weight(w) {}
    };

    vector<Edge> edges;
    vector<string> vertices;

public:
    Graph(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Failed to open file: " << filename << endl;
            return;
        }

        string src, dest;
        int weight;

        while (file >> src >> dest >> weight) {
            edges.push_back(Edge(src, dest, weight));
            if (find(vertices.begin(), vertices.end(), src) == vertices.end())
                vertices.push_back(src);
            if (find(vertices.begin(), vertices.end(), dest) == vertices.end())
                vertices.push_back(dest);
        }

        file.close();
    }

    /**
     * The findSet function finds the root of the set that i belongs to in the disjoint-set data structure.
     * @param parent
     * @param i
     * @return
     */
    int findSet(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return findSet(parent, parent[i]);
    }

    /**
     * The unionSets function unions two disjoint sets by their roots. It also keeps track of the size of each set
     * by maintaining a rank array.
     * @param parent
     * @param rank
     * @param i
     * @param j
     */
    void unionSets(vector<int>& parent, vector<int>& rank, int i, int j) {
        int iRoot = findSet(parent, i);
        int jRoot = findSet(parent, j);

        if (rank[iRoot] < rank[jRoot])
            parent[iRoot] = jRoot;
        else if (rank[iRoot] > rank[jRoot])
            parent[jRoot] = iRoot;
        else {
            parent[jRoot] = iRoot;
            rank[iRoot]++;
        }
    }

    /**
     * The function checks if the graph is conex or not. If it is not conex then we are not able to produce a
     * minimal spanning tree. It performs a BFS starting from the first vertex and checks if all vertices are visited.
     * If they are, then the graph is conex.
     * @return true or false depending on the conexity of the graph
     */
    bool isConex() {
        vector<bool> visited(vertices.size(), false);
        queue<int> q;
        q.push(0); // start BFS from the first vertex

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;

            for (int i = 0; i < edges.size(); i++) {
                if (edges[i].src == vertices[curr] && !visited[find(vertices.begin(), vertices.end(), edges[i].dest) - vertices.begin()]) {
                    q.push(find(vertices.begin(), vertices.end(), edges[i].dest) - vertices.begin());
                }
                else if (edges[i].dest == vertices[curr] && !visited[find(vertices.begin(), vertices.end(), edges[i].src) - vertices.begin()]) {
                    q.push(find(vertices.begin(), vertices.end(), edges[i].src) - vertices.begin());
                }
            }
        }

        // Check if all vertices are visited
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }

    /**
     * The function creates a minimal spanning tree using Kruskal's algorithm.
     * The function starts by checking if the graph is connected using the isConex() function.
     * If the graph is not connected, it prints an error message and returns without doing anything else.
     * If the graph is connected, the function initializes two arrays: parent and rank, both of size equal to
     * the number of vertices in the graph. These arrays are used to implement the disjoint-set data structure,
     * which is used to keep track of the connected components of the graph.
     * The function initializes the parent and rank arrays to represent each vertex as a separate disjoint set.
     * This is done using a for loop that goes through all vertices and sets their parent to their own index and their
     * rank to 0.
     * The function sorts the edges in the graph in ascending order of weight. This is done using the sort function from
     * the <algorithm> header and a lambda function that takes two edges a and b and returns true if a.weight is less
     * than b.weight. This will ensure that the algorithm considers edges with smaller weights first.
     * The function initializes an empty vector mst to store the edges of the minimum spanning tree, and a variable
     * mstWeight to keep track of the total weight of the MST.
     * The function then iterates through all edges in the sorted order.
     * For each edge, it finds the indices of its source and destination vertices in the vertices vector using the find
     * function. It then finds the roots of the sets that contain these vertices using the findSet function, which
     * implements the find operation of the disjoint-set data structure.
     * If the roots of the sets containing the source and destination vertices are different, it means that adding the
     * edge to the MST will not create a cycle. In this case, the function adds the edge to the mst vector, updates
     * the mstWeight variable, and merges the sets using the unionSets function, which implements the union operation
     * of the disjoint-set data structure.
     * After all edges have been processed,
     * the function prints the edges of the minimum spanning tree and the total weight of the MST.
     */
    void kruskalMST() {

        if (!isConex()) {
            cout << "Graph is not conex. Cannot create MST." << endl;
            return;
        }
        vector<int> parent(vertices.size());
        vector<int> rank(vertices.size());

        // Initialize parent and rank arrays
        for (int i = 0; i < vertices.size(); i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        // Sort edges in ascending order of weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<Edge> mst; // Minimum Spanning Tree
        int mstWeight = 0;

        for (const Edge& edge : edges) {
            int srcIdx = find(vertices.begin(), vertices.end(), edge.src) - vertices.begin();
            int destIdx = find(vertices.begin(), vertices.end(), edge.dest) - vertices.begin();

            int srcRoot = findSet(parent, srcIdx);
            int destRoot = findSet(parent, destIdx);

            if (srcRoot != destRoot) {
                mst.push_back(edge);
                mstWeight += edge.weight;
                unionSets(parent, rank, srcRoot, destRoot);
            }
        }

        // Print the Minimum Spanning Tree
        for (const Edge& edge : mst) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }

        cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << endl;
    }
};

int main() {
    Graph graph("../Land2.txt");
    graph.kruskalMST();
    return 0;

}
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:

    struct Node {
        string name;
        Node* next;
    };
    unordered_map<string, vector<string>> adjacencyList;


    /**
     * @briefThis function is a helper function used by the getConnectedComponents() function.
      @details It performs a depth-first search (DFS) to find all the vertices in a connected component starting from
      the startVertex.
      It updates the visited map to keep track of visited vertices and appends the vertices of the connected component
      to the components vector.
      The function recursively visits all adjacent vertices of each vertex and marks them as visited.
     * @param startVertex
     * @param visited
     * @param components
     */
    void getConnectedComponents(const string& startVertex, unordered_map<string, bool>& visited, vector<vector<string>>& components) {
        visited[startVertex] = true;
        components.back().push_back(startVertex);

        for (const string& adjacentVertex : adjacencyList[startVertex]) {
            if (!visited[adjacentVertex]) {
                getConnectedComponents(adjacentVertex, visited, components);
            }
        }
    }

    /**
     *@brief This function checks if a given connected component is Eulerian or not.
      @details It takes a vector of strings representing the vertices of the component as input. It iterates over each
      vertex in the component and checks if the degree of each vertex (number of adjacent vertices) is even. If all
      vertices have even degrees, it returns true, indicating that the component is Eulerian. Otherwise, it returns
      false.
     * @param component
     * @return
     */
    bool isEulerianComponent(const vector<string>& component) {
        for (const string& vertex : component) {
            if (adjacencyList[vertex].size() % 2 != 0) {
                return false;
            }
        }
        return true;
    }

public:

    /**
     * @briefThis is the constructor of the Graph class, which takes a filename as input.
       @details It reads the graph data from the specified file and builds the adjacency list representation of the
       graph. The graph data in the file is assumed to be in the format of pairs of city names representing edges
       between cities.
       For each edge, it adds the corresponding vertices to the adjacency list, taking care to add each vertex to the
       adjacency list of the other vertex as well, since the graph is undirected.
     * @param filename
     */
    Graph(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Failed to open the file." << endl;
            return;
        }
        string city1, city2;
        while (inputFile >> city1 >> city2) {
            adjacencyList[city1].push_back(city2);
            adjacencyList[city2].push_back(city1);
        }
        inputFile.close();
    }

    /**
     * @brief This function finds the Eulerian paths in the graph.
       @detailscIt first initializes empty vectors eulerianPaths and components to store the found Eulerian paths
       and connected components, respectively. It calls the getConnectedComponents() function to find all the connected
       components in the graph. For each component, it checks if the component is Eulerian using the
       isEulerianComponent() function. If a component is not Eulerian, it skips it and moves to the next component.
        For each Eulerian component, it initializes a component-specific adjacency list, componentAdjacencyList,
        based on the main adjacency list of the graph. It then proceeds to find the Eulerian path for each starting
        vertex with an odd degree in the component using a depth-first search (DFS) with a stack. The found Eulerian
        path is reversed to obtain the correct order of vertices. Finally, the Eulerian paths for each component are
        added to the eulerianPaths vector, which is returned.
     * @return
     */
    vector<vector<string>> getEulerianPath() {
        vector<vector<string>> eulerianPaths;
        vector<vector<string>> components;

        unordered_map<string, bool> visited;
        for (const auto& entry : adjacencyList) {
            if (!visited[entry.first]) {
                components.push_back({});
                getConnectedComponents(entry.first, visited, components);
            }
        }

        for (const auto& component : components) {
            if (!isEulerianComponent(component)) {
                continue; // Skip non-Eulerian components
            }

            // Initialize component adjacency list
            unordered_map<string, vector<string>> componentAdjacencyList;
            for (const string& vertex : component) {
                componentAdjacencyList[vertex] = adjacencyList[vertex];
            }

            vector<string> eulerianPath;

            // Find vertices with odd degrees in the component
            vector<string> oddDegreeVertices;
            for (const string& vertex : component) {
                if (componentAdjacencyList[vertex].size() % 2 != 0) {
                    oddDegreeVertices.push_back(vertex);
                }
            }

            // If all vertices have even degrees, start from any vertex
//            if (oddDegreeVertices.empty()) {
//                oddDegreeVertices.push_back(component.front());
//            }

            //If all vertices have even degrees, start from the vertex that represents Sibiu

            if (oddDegreeVertices.empty()) {
                oddDegreeVertices.push_back("Sibiu");
            }

            // Process each component separately
            for (const string& startVertex : oddDegreeVertices) {
                stack<string> dfsStack;
                dfsStack.push(startVertex);

                while (!dfsStack.empty()) {
                    string currentVertex = dfsStack.top();

                    if (componentAdjacencyList[currentVertex].empty()) {
                        // If there are no unvisited edges from the current vertex, add it to the path
                        eulerianPath.push_back(currentVertex);
                        dfsStack.pop();
                    } else {
                        // Otherwise, choose an adjacent vertex and remove the edge
                        string nextVertex = componentAdjacencyList[currentVertex].back();
                        componentAdjacencyList[currentVertex].pop_back();
                        componentAdjacencyList[nextVertex].erase(find(componentAdjacencyList[nextVertex].begin(), componentAdjacencyList[nextVertex].end(), currentVertex));
                        dfsStack.push(nextVertex);
                    }
                }
            }

            // Reverse the path to get the Eulerian path
            reverse(eulerianPath.begin(), eulerianPath.end());
            eulerianPaths.push_back(eulerianPath);
        }

        return eulerianPaths;
    }



};





int main() {
    Graph graph("../Land2.txt");
    vector<vector<string>> eulerianPaths = graph.getEulerianPath();

    if (eulerianPaths.empty()) {
        cout << "No Eulerian path found." << endl;
    } else {
        cout << "Eulerian paths:" << endl;
        for (const auto& component : eulerianPaths) {
            cout << "Component: ";
            for (const string& city : component) {
                cout << city << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

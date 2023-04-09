#include "Graph.h"

Graph::Graph() {}

Graph::Graph(int size) {
    this->size = size;
    adjacencyMatrix.resize(size, vector<int>(size, 0));
}

Graph::Graph(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        file >> size;
        //Resize the adjacency matrix to the correct size and initialize all values to 0.
        adjacencyMatrix.resize(size, vector<int>(size, 0));
        //Read the adjacency matrix from the file.
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> adjacencyMatrix[i][j];
            }
        }
    }
    file.close();
}

void Graph::BFS(int x) {
    //The vector visited is used to keep track of the visited nodes.
    vector<bool> visited(size, false);
    //The queue q is used to keep track of the nodes to be visited.
    queue<int> q;
    //The node x is marked as visited and added to the queue.
    visited[x] = true;
    q.push(x);

    //While the queue is not empty, the first element is removed and printed.
    while (!q.empty()) {
        //Get the first element of the queue and store it in the variable current.
        int current = q.front();
        //The first element of the queue is removed.
        cout << current << " ";
        q.pop();
        //The adjacent nodes of the current node are added to the queue.
        for (int i = 0; i < size; i++) {
            //If the node is not visited, it is marked as visited and added to the queue.
            if (adjacencyMatrix[current][i] == 1 && !visited[i]) {
                //The node is marked as visited.
                visited[i] = true;
                //The node is added to the queue.
                q.push(i);
            }
        }
    }
}


void Graph::printConexComponent(Graph g) {
    //Initialize the number of connected components to 0.
    int numComponents = 0;
    //The vector visited is used to keep track of the visited nodes.
    vector<bool> visited(size, false);

    //Loop through all nodes in the graph
    for (int i = 0; i < size; i++) {
        //If the node is not visited, it is the start of a new connected component.
        if (!visited[i]) {
            //Increment the number of connected components.
            numComponents++;
            //Print the connected component.
            cout << "Component " << numComponents << ": ";
            //The queue q is used to keep track of the nodes to be visited.
            queue<int> q;
            //The node i is marked as visited and added to the queue.
            visited[i] = true;
            //The node i is added to the queue.
            q.push(i);
            //While the queue is not empty, the first element is removed and printed.
            while (!q.empty()) {
                //Get the first element of the queue and store it in the variable current.
                int current = q.front();
                cout << current << " ";
                //The first element of the queue is removed.
                q.pop();
                //The adjacent nodes of the current node are added to the queue.
                for (int j = 0; j < size; j++) {
                    //If the node is not visited, it is marked as visited and added to the queue.
                    if (adjacencyMatrix[current][j] == 1 && !visited[j]) {
                        //The node is marked as visited.
                        visited[j] = true;
                        //The node is added to the queue.
                        q.push(j);
                    }
                }
            }
            cout << endl;
        }
    }
    cout << "Number of connected components: " << numComponents << endl;
}

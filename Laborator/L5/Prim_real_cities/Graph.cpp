#include <iostream>
#include <fstream>
#include "Graph.h"


using namespace std;


Graph::Graph(const string &filename) {
    ifstream file(filename);

    string from, to;
    int weight;

    while (file >> from >> to >> weight) {
        adjacencyList[from].emplace_back(to, weight);
        adjacencyList[to].emplace_back(from, weight);
    }

    for (const auto& vertex : adjacencyList) {
        visited[vertex.first] = false;
    }

    file.close();
}


void Graph::primMST() {
    string startVertex = adjacencyList.begin()->first;
    int minCost = 0;

    pq.emplace(0, startVertex);

    while (!pq.empty()) {
        string currentVertex = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        if (visited[currentVertex]) {
            continue;
        }

        visited[currentVertex] = true;
        minCost += currentWeight;

        cout << "From: " << currentVertex << endl;
        cout << "To\tWeight" << endl;

        for (const auto& neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor.first]) {
                pq.emplace(neighbor.second, neighbor.first);
            }
            cout << neighbor.first << "\t" << neighbor.second << endl;
        }

        cout << endl;
    }

    cout << "Minimum cost of the MST: " << minCost << endl;
}
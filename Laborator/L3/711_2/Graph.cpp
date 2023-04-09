//
// Created by Luca Tudor on 06.04.2023.
//
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;


/**
 * Default constructor
 */
Graph::Graph() = default;


/**
 *
 * @param fileName
 * Reads the graph from a file
 * The first line contains the number of nodes
 * The second line contains the number of edges
 * The following lines contain the edges
 * The edges are represented by two numbers, the first number is the node and the second number is the connected node
 * The nodes are numbered from 0 to n-1
 * The file is in the following format:
 */
Graph::Graph(const string &fileName) {
    ifstream file(fileName);

    if(!file.is_open()){
        cerr << "File not found" << endl;
        exit(1);
    }
    file >> nodes;
    file >> edges;
    adjacencyList.resize(nodes);

    for(int i = 0; i <  edges; i++){
        int node, connectedNode;
        file >> node >> connectedNode;
        adjacencyList[node].push_back(connectedNode);
        adjacencyList[connectedNode].push_back(node);
    }

    file.close();
}


/**
 * Copy constructor
 * @param other
 */

Graph::Graph(const Graph &other) {
    nodes = other.nodes;
    edges = other.edges;
    adjacencyList = other.adjacencyList;
}


/**
 * Print the graph on the screen
 * The graph is printed in the following format:
 * 0: 1 2 3
 * 1: 0 2
 * 2: 0 1 3
 * 3: 0 2
 * The first number is the node and the following numbers are the connected nodes
 * The nodes are numbered from 0 to n-1
 */
void Graph::text() {
    for(int i = 0; i < nodes; i++){
        cout << i << ": ";
        for(int j : adjacencyList[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

/**
 * BFS algorithm
 * @details The algorithm starts at the node start and prints the nodes in the order in which they are visited
 * @param start
 * The algorithm starts at the node start
 * The algorithm prints the nodes in the order in which they are visited
 *
 *
 */
void Graph::BFS(int start) {
    //Create a vector of booleans to mark the visited nodes
    vector<bool> visited(nodes, false);
    //Create a queue to store the nodes
    queue<int> queue;

    //Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push(start);

    //Loop until the queue is empty
    while(!queue.empty()){
        //Dequeue a node from the queue and print it
        int node = queue.front();
        queue.pop();
        cout << node << " ";

        //Get all adjacent nodes of the dequeued node
        for(int i : adjacencyList[node]){
            //If an adjacent node is not visited, mark it as visited and enqueue it
            if(!visited[i]){
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    cout << endl;
}

//Implement a method void away(int start, int stop), which shows a path of minimum length with the help of width search between start and stop and displays it on the screen. If such a Way does not exist, as the message "no way" written on the screen.
int Graph::weg(int start, int stop) const {
    //Create a vector of booleans to mark the visited nodes
    vector<bool> visited(nodes, false);
    //Create a queue to store the nodes
    vector<int> distance(nodes, -1);
    //Create a vector to store the parent of each node
    vector<int> parent(nodes, -1);

    //Mark the current node as visited and enqueue it
    queue<int> q;
    visited[start] = true;
    distance[start] = 0;
    q.push(start);

    //Loop until the queue is empty
    while(!q.empty()) {
        //Dequeue a node from the queue and print it
        int node = q.front();
        q.pop();

        //Get all adjacent nodes of the dequeued node
        for(int v : adjacencyList[node]) {
            //If an adjacent node is not visited, mark it as visited and enqueue it
            if(!visited[v]) {
                visited[v] = true;
                distance[v] = distance[node] + 1;
                parent[v] = node;
                q.push(v);

                //If the node is the stop node, print the path
                if(v == stop) {
                    cout << "The shortest path is: ";
                    int current = v;
                    //Print the path from the stop node to the start node
                    while(current != -1) {
                        cout << current << " ";
                        current = parent[current];
                    }
                    cout << endl;
                    //Return the distance
                    return distance[v];
                }
            }
        }
    }
    //If the stop node is not visited, there is no path
    cout << "Kein weg" << endl;
    return -1;
}
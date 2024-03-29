//
// Created by Luca Tudor on 06.04.2023.
//

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <deque>

using std::vector, std::string;

class Graph{
private:
    //Number of nodes
    int nodes{};
    //Number of edges
    int edges{};
    //Adjacency list
    vector<vector<int>> adjacencyList;

public:
    //Default constructor
    Graph();

    //Constructor with 1 parameter
    Graph(const string &fileName);

    //Copy constructor
    Graph(const Graph &other);

    //Print the graph on the screen
    void text();

    //BFS algorithm
    void BFS(int start);

    //Find the way between two nodes
    [[nodiscard]] int weg(int start, int stop) const;
};
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>


template<typename T>
Graph<T>::Graph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return;
    }
    T source, dest;
    int weight;
    while (file >> source >> dest >> weight) {
        add_edge(source, dest, weight);
    }
}

template<typename T>
void Graph<T>::add_edge(T source, T dest, int weight) {
    adj_list[source].push_back(std::make_pair(dest, weight));
    adj_list[dest].push_back(std::make_pair(source, weight)); // Undirected graph
}

template<typename T>
void Graph<T>::dijkstra(T source) {
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;
    std::unordered_map<T, int> dist; // Map to store shortest distance from source to each vertex
    for (auto it = adj_list.begin(); it != adj_list.end(); it++) {
        dist[it->first] = INT_MAX;
    }
    dist[source] = 0; // Distance to source is 0
    pq.push(std::make_pair(0, source)); // Push source vertex with distance 0 to the priority queue

    while (!pq.empty()) {
        T curr_vertex = pq.top().second;
        pq.pop();
        for (auto it = adj_list[curr_vertex].begin(); it != adj_list[curr_vertex].end(); it++) {
            T adj_vertex = it->first;
            int weight = it->second;
            if (dist[curr_vertex] + weight < dist[adj_vertex]) { // If new distance to adjacent vertex is shorter than previous
                dist[adj_vertex] = dist[curr_vertex] + weight; // Update distance
                pq.push(std::make_pair(dist[adj_vertex], adj_vertex)); // Push updated vertex and distance to priority queue
            }
        }
    }

    // Print shortest distances
    for (auto it = dist.begin(); it != dist.end(); it++) {
        std::cout << "Shortest distance from " << source << " to " << it->first << " is " << it->second << std::endl;
    }
}


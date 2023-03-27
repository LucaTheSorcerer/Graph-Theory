#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph(vector<pair<int, int>> &edge_list) {
    this->edge_list = edge_list;
}

Graph::Graph() = default;

void Graph::leseDateiZuGraph(const string &datei) {
    ifstream f;
    f.open(datei);
    f >> n;
    f >> m;

    for (int i = 0; i < m; i++) {
        pair<int, int> tmp{};
        f >> tmp.first;
        f >> tmp.second;

        edge_list.push_back(tmp);
    }
}

void Graph::zeigeKantenListe() const {
    for (const auto &edge: edge_list)
        cout << edge.first << ' ' << edge.second << '\n';
}

void Graph::zeigeAngrenzendeKnoten(int _n) const {
    for (const auto &edge: edge_list) {
        if (edge.first == _n)
            cout << edge.second << ' ';
        else if (edge.second == _n)
            cout << edge.first << ' ';
    }
}

Graph Graph::vereinigungVonGraphen(Graph &g1, Graph &g2) {
    Graph res{g1.edge_list};
    for (const auto &edge: g2.edge_list)
        if (!res.isEdgeInGraph(edge)) {
            res.edge_list.push_back(edge);
        }

    return res;
}

bool Graph::isEdgeInGraph(const pair<int, int> &edge) const {
    for (const auto &e: edge_list)
        if (e.first == edge.first && e.second == edge.second ||
            e.first == edge.second && e.second == edge.first)
            return true;

    return false;
}

bool Graph::isVertexInGraph(int _n) const {
    for (const auto &e: edge_list)
        if (e.first == _n || e.second == _n)
            return true;

    return false;
}

void Graph::schreibeGemeinsameKnotenUndKanten(Graph &union_graph, const string &datei) {
    ofstream f(datei);
    vector<int> common_nodes;
    vector<pair<int, int>> common_edges;
    for (const auto &edge1: edge_list) {
        for (const auto &edge2: union_graph.edge_list) {
            if (edge1 == edge2) {
                if (find(common_edges.begin(), common_edges.end(), edge1) == common_edges.end())
                    common_edges.push_back(edge1);
                if (find(common_nodes.begin(), common_nodes.end(), edge1.first) == common_nodes.end())
                    common_nodes.push_back(edge1.first);
                if (find(common_nodes.begin(), common_nodes.end(), edge1.second) == common_nodes.end())
                    common_nodes.push_back(edge1.second);
            }
        }
    }
    f << "Gemeinsame Knoten: ";
    for (const auto &node: common_nodes)
        f << node << ' ';
    f << '\n';
    f << "Gemeinsame Kanten: ";
    for (const auto &edge: common_edges)
        f << "[" << edge.first << " " << edge.second << "] ";
    f << '\n';
    f.close();
}
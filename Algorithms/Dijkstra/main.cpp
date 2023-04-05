#include <iostream>
#include <string>
#include "Graph.h"
#include "Graph.cpp"

using namespace std;

int main() {
    Graph<int> g_int("../graph_int.in");
    int source_int = 1;
    g_int.dijkstra(source_int);

    cout << endl;

    Graph<string> g_string("../graph_str.in");
    string source_string = "A";
    g_string.dijkstra(source_string);

    return 0;
}

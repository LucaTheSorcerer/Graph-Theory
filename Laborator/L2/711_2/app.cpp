#include "Graph.h"
#include<iostream>
#include<fstream>

using namespace std;

int main() {
    Graph g1{};
    g1.leseDateiZuGraph("../kanten.in");
    g1.zeigeKantenListe();
    g1.zeigeAngrenzendeKnoten(1);

    return 0;
}

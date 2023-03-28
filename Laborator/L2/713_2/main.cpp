#include <iostream>
#include "Graph.h"

int main() {
    Graph g("../filename.txt");

    std::cout << "A path between two nodes is: " << std::endl;
    g.printPfad(1, 2);

    Graph g2(g);

    Graph g3();

    std::cout << "A path between two nodes in g2 is: " << std::endl;
    g2.printPfad(1, 0);
    return 0;

    // 1 merge la 0 si 0 merge la 2
    // 1 merge la 3 si 3 merge la 2
    //1 e adiacent cu 0 si 3
    //2 e adiacent cu 0 si 3


}

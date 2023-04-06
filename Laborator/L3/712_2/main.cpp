#include "Graph.h"
#include <iostream>



int main() {
    Graph g1("../10k.txt");
    g1.text();
    g1.BFS(0);
    std::cout << std::endl;
    std::cout << g1.weg(0, 7738) << std::endl;
    std::cout << g1.weg(793, 6174) << std::endl;

    Graph g2("../100k.txt");
    g2.text();
    g2.BFS(0);
    std::cout << std::endl;
    std::cout << g2.weg(81768, 55850) << std::endl;
    std::cout << g2.weg(19126, 53548) << std::endl;

    Graph g3("../1M.txt");
    g3.text();
    g3.BFS(0);
    std::cout << std::endl;
    std::cout << g3.weg(696751, 505396) << std::endl;
    std::cout << g3.weg(0, 895812) << std::endl;
    return 0;
}
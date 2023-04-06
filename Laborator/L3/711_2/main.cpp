#include <iostream>
#include "Graph.h"

int main() {
    Graph g1("../10k.txt");
    Graph g2("../100k.txt");
    Graph g3("../1M.txt");

    std::cout << "Graph g1:" << std::endl;
    g1.text();

    std::cout << std::endl;

    std::cout << "BFS from 0:" << std::endl;
    g1.BFS(0);

    std::cout << std::endl;

    std::cout << "Path from 0 to 7738" << g1.weg(0, 7738) << std::endl;

    std::cout << std::endl;

    std::cout << "Path from 793 to 6174" << g1.weg(793, 6174) << std::endl;


    std::cout << std::endl;

    std::cout << "Graph g2:" << std::endl;
    g2.text();

    std::cout << std::endl;

    std::cout << "BFS from 0:" << std::endl;
    g2.BFS(0);

    std::cout << std::endl;

    std::cout << "Path from 81768 to 55850" << g2.weg(81768, 55850) << std::endl;

    std::cout << std::endl;

    std::cout << "Path from 19126 to 53548" << g2.weg(19126, 53548) << std::endl;

    std::cout << std::endl;

    std::cout << "Graph g3:" << std::endl;
    g3.text();

    std::cout << std::endl;

    std::cout << "BFS from 0:" << std::endl;
    g3.BFS(0);

    std::cout << std::endl;

    std::cout << "Path from 696751 to 505396" << g3.weg(696751, 505396) << std::endl;

    std::cout << std::endl;

    std::cout << "Path from 0 to 895812" << g3.weg(0, 895812) << std::endl;

    std::cout << std::endl;

    return 0;

}

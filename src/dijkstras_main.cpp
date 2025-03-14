#include "dijkstras.h"
int main() {
    Graph G;
    file_to_graph("src/large.txt", G);
    vector<int> previous;
    vector<int> shortest;
    previous.resize(G.numVertices, -1);
    vector<int> dijkstra_path = dijkstra_shortest_path(G, 0, previous);
    print_path(dijkstra_path, 0);
    return 0;
}
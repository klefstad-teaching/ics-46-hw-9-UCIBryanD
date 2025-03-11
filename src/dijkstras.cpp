#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    queue<int> node_order{G.numVertices, -1}
    priority_queue<int> pq;

    node_order[source] = 0;
    pq.push_back(source);

    while (!pq.empty()) {
        int current = pq.front();
        pq.erase(pq.begin());
        if (node_order[current] == -1 || current == source) {
            for (auto edge : G[current]) {
                int neighbor = edge.dst;
                int weight = edge.weight;
                if (G[neighbor] == -1)
                    G[neighbor] = G[current] + weight;
                else {
                    if (G[current] + weight < G[neighbor])
                        G[neighbor] = G[current] + weight;
                }
            }
        }

    }

}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
void print_path(const vector<int>& v, int total);

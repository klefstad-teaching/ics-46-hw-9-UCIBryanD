#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    queue<int> node_order{G.numVertices, -1}
    priority_queue<int> pq;

    //node_order[source] = 0;
    pq.push_back(source);

    while (!pq.empty()) {
        int current = pq.front();
        pq.erase(pq.begin());
        if (node_order[current] == -1) {
            if (current == source) {
                node_order[current] = 0;
                continue;
            }
            
            for (auto edge : G[current]) {
                int neighbor = edge.dst;
                int weight = edge.weight;
                if ()
            }
        }

    }

}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
void print_path(const vector<int>& v, int total);

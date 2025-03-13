#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int num_vertices = G.numVertices;
    vector<int> distances{num_vertices, INF};
    vector<bool> visited;
    visited.resize(num_vertices, false);
    distances[source] = 0;
    previous[source] = source;
    
    priority_queue<pair<int, int>> min_heap;
    min_heap.push({source, 0});

    while(!min_heap.empty()) {
        int u = min_heap.top().first;
        min_heap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                min_heap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (; destination != previous[destination]; destination = previous[destination])
        path.push_back(destination);
    path.push_back(destination);
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (auto vertex : v)
        cout << vertex << " ";
    cout << endl << "Total cost is " << total << endl;
}

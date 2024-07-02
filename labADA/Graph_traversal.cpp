#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>>& graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap (distance, vertex)
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<Edge>> graph(V);

    // Add edges
    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({3, 6});
    graph[1].push_back({2, 2});
    graph[2].push_back({4, 4});
    graph[3].push_back({4, 6});
    graph[3].push_back({5, 5});
    graph[4].push_back({5, 1});

    // Run Dijkstra's algorithm from vertex 0
    dijkstra(graph, 0);

    return 0;
}

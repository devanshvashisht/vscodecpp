#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int dest;
    int weight;
};

struct Node {
    vector<Edge> edges;
};

void prim(vector<Node>& graph, int startNode) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);
    int totalWeight = 0;
    pq.push(make_pair(0, startNode));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.second;
        int w = top.first;
        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;
        cout << "Edge: " << u << " -> " << w << endl;
        for (auto edge : graph[u].edges) {
            int v = edge.dest;
            int weight = edge.weight;
            if (!visited[v]) {
                pq.push(make_pair(weight, v));
            }
        }
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    vector<Node> graph(5);
    graph[0].edges.push_back({1, 2});
    graph[0].edges.push_back({3, 6});
    graph[1].edges.push_back({0, 2});
    graph[1].edges.push_back({2, 3});
    graph[1].edges.push_back({3, 8});
    graph[1].edges.push_back({4, 5});
    graph[2].edges.push_back({1, 3});
    graph[2].edges.push_back({4, 7});
    graph[3].edges.push_back({0, 6});
    graph[3].edges.push_back({1, 8});
    graph[4].edges.push_back({1, 5});
    graph[4].edges.push_back({2, 7});
    prim(graph, 0);
    return 0;
}

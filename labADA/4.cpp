#include <iostream>
#include <list>

class Graph {
private:
    int V; // Number of vertices
    std::list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to the graph
    void printGraph(); // Function to print the adjacency list representation of the graph
};

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Adjacency list representation of the graph:" << std::endl;
    g.printGraph();

    return 0;
}
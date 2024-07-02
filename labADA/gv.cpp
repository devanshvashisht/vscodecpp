#include <iostream>
#include <vector>
using namespace std;

// Node class to represent a vertex in the graph
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Graph class to represent a graph using adjacency list
class Graph {
private:
    vector<Node*> adjacencyList;
    int a;

public:
    Graph(int a) {
        this->a = a;
        adjacencyList.resize(a, NULL);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        // Add edge from src to dest
        Node* newNode = new Node(dest);
        newNode->next = adjacencyList[src];
        adjacencyList[src] = newNode;

        // Since the graph is undirected, add an edge from dest to src as well
        newNode = new Node(src);
        newNode->next = adjacencyList[dest];
        adjacencyList[dest] = newNode;
    }

    // Function to print the graph
    void printGraph() {
        for (int i = 0; i < a; ++i) {
            Node temp = adjacencyList[i];
            cout << "Vertex " << i << ":";
            while (temp) {
                cout << " -> " << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the graph
    graph.printGraph();

    return 0;
}

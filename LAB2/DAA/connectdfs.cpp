#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int from, int to);
    bool isConnected();

private:
    int vertices;
    vector<vector<int>> adjacencyList;
    void DFS(int node, vector<bool>& visited);
};

Graph::Graph(int vertices) : vertices(vertices), adjacencyList(vertices) {}

void Graph::addEdge(int from, int to) {
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from);  // For an undirected graph, you need to add edges in both directions.
}

void Graph::DFS(int node, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}

bool Graph::isConnected() {
    vector<bool> visited(vertices, false);
    DFS(0, visited);  // Start DFS from any node, e.g., node 0.

    return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (from to):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    if (graph.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int from, int to);
    void BFS(int startNode);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int from, int to) {
    adjacencyList[from].push_back(to);
}

void Graph::BFS(int startNode) {
    vector<bool> visited(vertices, false);
    queue<int> queue;

    visited[startNode] = true;
    queue.push(startNode);

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();
        cout << currentNode << " ";

        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
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

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Nodes reachable from node " << startNode << " using BFS: ";
    graph.BFS(startNode);

    return 0;
}

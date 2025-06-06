#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);

        cout << "DFS Traversal: ";
        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (!visited[v]) {
                visited[v] = true;
                cout << v << " ";
                for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(0); // Start from vertex 0

        int visitedCount = 0;
        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (!visited[v]) {
                visited[v] = true;
                visitedCount++;
                for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }

        return visitedCount == V; // If all vertices are visited, the graph is connected
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    auto start = high_resolution_clock::now();
    cout << "Depth First Traversal starting from vertex 0:\n";
    g.DFS(0);

    if (g.isConnected()) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }
    auto end = high_resolution_clock::now();

    cout << "Execution time: " 
         << duration_cast<nanoseconds>(end - start).count() << " ns\n";

    return 0;
}
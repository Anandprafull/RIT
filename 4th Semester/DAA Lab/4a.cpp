#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int v, int w) { adj[v].push_back(w); }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) DFS(neighbor, visited);
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 2); g.addEdge(2, 3);
    
    vector<bool> visited(4, false);
    cout << "DFS Traversal: ";
    g.DFS(0, visited);
    cout << endl;

    return 0;
}

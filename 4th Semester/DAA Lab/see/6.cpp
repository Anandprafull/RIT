#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

// DFS function
void dfs(int start, int adj[][100], int adjSize[], bool visited[]) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        for (int i = adjSize[node] - 1; i >= 0; --i) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    int adj[100][100];
    int adjSize[100] = {0};
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    bool visited[100] = {false};

    clock_t start = clock();
    dfs(0, adj, adjSize, visited);
    clock_t end = clock();

    // Check connectivity
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    cout << (connected ? "Graph is connected" : "Graph is not connected") << endl;
    cout << "Time: " << double(end - start) / CLOCKS_PER_SEC * 1e9 << " ns" << endl;

    return 0;
}
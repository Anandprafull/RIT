#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void addEdge(int adj[][100], int adjSize[], int u, int v) {
    adj[u][adjSize[u]++] = v;
    adj[v][adjSize[v]++] = u;
}

void BFS(int adj[][100], int adjSize[], int V, int start) {
    bool visited[101] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < adjSize[current]; i++) {
            int neighbor = adj[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    int adj[101][100];
    int adjSize[101] = {0};
    
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, adjSize, u, v);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    clock_t start_time = clock();
    BFS(adj, adjSize, V, start);
    clock_t end_time = clock();

    cout << "Time: " << double(end_time - start_time) / CLOCKS_PER_SEC * 1e9 << " ns" << endl;

    return 0;
}
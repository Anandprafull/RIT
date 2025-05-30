#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

class Graph {
    int V;
    vector<vector<int>> adj;

    void dfsUtil(int v, vector<bool>& visited, stack<int>& topoStack) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, topoStack);
            }
        }
        topoStack.push(v);
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSortDFS() {
        vector<bool> visited(V, false);
        stack<int> topoStack;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsUtil(i, visited, topoStack);
            }
        }

        cout << "Topological Sort (DFS-based): ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << endl;
    }

    void topologicalSortKahn() {
        vector<int> inDegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int v : topoOrder) {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    auto startDFS = high_resolution_clock::now();
    g.topologicalSortDFS();
    auto endDFS = high_resolution_clock::now();
    cout << "DFS-based Topological Sort Execution time: "
         << duration_cast<nanoseconds>(endDFS - startDFS).count() << " ns\n";

    auto startKahn = high_resolution_clock::now();
    g.topologicalSortKahn();
    auto endKahn = high_resolution_clock::now();
    cout << "Kahn's Algorithm Topological Sort Execution time: "
         << duration_cast<nanoseconds>(endKahn - startKahn).count() << " ns\n";

    return 0;
}
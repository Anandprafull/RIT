#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
using namespace std;

// Global arrays
int adj[100][100];
int adjSize[100] = {0};
bool visited[100];
int inDegree[100];
int topoOrder[100];
int V;

void dfsUtil(int v, stack<int>& s) {
    visited[v] = true;
    for (int i = 0; i < adjSize[v]; i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor]) {
            dfsUtil(neighbor, s);
        }
    }
    s.push(v);
}

void topoDFS() {
    for (int i = 0; i < V; i++) visited[i] = false;
    stack<int> s;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsUtil(i, s);
        }
    }
    
    cout << "DFS Topo Sort: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void topoKahn() {
    // Calculate in-degrees
    for (int i = 0; i < V; i++) inDegree[i] = 0;
    for (int u = 0; u < V; u++) {
        for (int i = 0; i < adjSize[u]; i++) {
            inDegree[adj[u][i]]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder[count++] = u;
        
        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    cout << "Kahn Topo Sort: ";
    for (int i = 0; i < count; i++) {
        cout << topoOrder[i] << " ";
    }
    cout << endl;
}

void addEdge(int u, int v) {
    adj[u][adjSize[u]++] = v;
}

int main() {
    V = 6;
    addEdge(5, 2); addEdge(5, 0); addEdge(4, 0);
    addEdge(4, 1); addEdge(2, 3); addEdge(3, 1);
    
    clock_t start = clock();
    topoDFS();
    clock_t end = clock();
    cout << "DFS Time: " << double(end - start) / CLOCKS_PER_SEC * 1e9 << " ns\n";
    
    start = clock();
    topoKahn();
    end = clock();
    cout << "Kahn Time: " << double(end - start) / CLOCKS_PER_SEC * 1e9 << " ns\n";
    
    return 0;
}


------------------------------
#include <iostream>
#include <queue>
using namespace std;

int adj[6][6] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0}};
int deg[6], vis[6], res[6], k;

void dfs(int v)
{
    vis[v] = 1;
    for (int i = 0; i < 6; i++)
        if (adj[v][i] && !vis[i])
            dfs(i);
    res[k++] = v;
}

int main()
{
    for (int i = 0; i < 6; i++)
        if (!vis[i])
            dfs(i);
    cout << "DFS: ";

    for (int i = k - 1; i >= 0; i--)
        cout << res[i] << " ";

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            deg[i] += adj[j][i];
    queue<int> q;
    for (int i = 0; i < 6; i++)
        if (!deg[i])
            q.push(i);
    cout << "\nKahn: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < 6; i++)
            if (adj[u][i] && --deg[i] == 0)
                q.push(i);
    }
}
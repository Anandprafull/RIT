#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
#define INF 99999

// Prim's Algorithm (Adjacency Matrix)
void primMST(vector<vector<int>>& graph, int V, int start=0) {
    vector<int> key(V, INF), parent(V, -1);
    vector<bool> inMST(V, false);
    key[start] = 0;
    int total = 0;
    for(int count=0; count<V-1; count++) {
        int u = -1, minKey = INF;
        for(int v=0; v<V; v++) if(!inMST[v] && key[v]<minKey) u=v, minKey=key[v];
        if(u==-1) break;
        inMST[u]=true;
        for(int v=0; v<V; v++) {
            if(graph[u][v] && !inMST[v] && graph[u][v]<key[v]) {
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    cout << "\nPrim's MST Edges:\n";
    for(int i=0;i<V;i++) if(parent[i]!=-1) {
        cout << parent[i] << " - " << i << "\tWeight: " << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }
    cout << "Total weight: " << total << endl;
}

// Kruskal's Algorithm (Edge List)
struct Edge {
    int u, v, w;
    bool operator<(const Edge& e) const { return w < e.w; }
};
int find(vector<int>& p, int x) { return p[x]==x ? x : p[x]=find(p,p[x]); }
void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end());
    vector<int> p(V); for(int i=0;i<V;i++) p[i]=i;
    int total=0, cnt=0;
    cout << "\nKruskal's MST Edges:\n";
    for(auto& e: edges) {
        int a=find(p,e.u), b=find(p,e.v);
        if(a!=b) {
            cout << e.u << " - " << e.v << "\tWeight: " << e.w << endl;
            total+=e.w; p[a]=b; cnt++;
            if(cnt==V-1) break;
        }
    }
    cout << "Total weight: " << total << endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for(int i=0;i<V;i++) for(int j=0;j<V;j++) cin >> graph[i][j];
    // Prim's Algorithm
    clock_t start = clock();
    primMST(graph, V, 0); // start from 0
    clock_t end = clock();
    cout << "Prim's Time: " << (double)(end-start)/CLOCKS_PER_SEC << " seconds\n";
    // Kruskal's Algorithm
    vector<Edge> edges;
    for(int i=0;i<V;i++) for(int j=i+1;j<V;j++) if(graph[i][j])
        edges.push_back({i,j,graph[i][j]});
    start = clock();
    kruskalMST(edges, V);
    end = clock();
    cout << "Kruskal's Time: " << (double)(end-start)/CLOCKS_PER_SEC << " seconds\n";
    return 0;
}

#include <iostream>
using namespace std;
const int INF = 1e9; // Represents infinity
// Maximum number of vertices
const int MAX = 100;
// Adjacency matrix to store weights
int graph[MAX][MAX];
// Array to track if a vertex is included in MST
bool visited[MAX];
// Stores the minimum edge weight to connect to MST
int key[MAX];
// To store the parent of each node in MST
int parent[MAX];
// Function to find the vertex with the minimum key value not yet included in MST
int findMinKey(int V) {
    int min = INF, minIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}
// Prim's Algorithm implementation
void primMST(int V) {
    // Initialize key values and visited array
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    // Start from the first vertex (0-based index)
    key[0] = 0;
    // MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = findMinKey(V);
        visited[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            // Check if there's an edge, and v is not yet in MST, and weight is smaller than current key
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST and total weight
    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (weight = " << graph[i][parent[i]] << ")\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total weight of MST = " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Initialize graph with 0
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    cout << "Enter edges in format: u v weight (0-based index)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    primMST(V);

    return 0;
}

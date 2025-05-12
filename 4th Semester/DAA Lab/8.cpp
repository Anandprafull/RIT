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

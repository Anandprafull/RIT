#include <iostream>
#include <climits>
#define V 5
const char* homes[V] = {"A", "B", "C", "D", "E"};
int minKey(int key[], bool mstSet[]) {
    int m = INT_MAX, idx = -1;
    for (int v = 0; v < V; v++) if (!mstSet[v] && key[v] < m) m = key[v], idx = v;
    return idx;
}
void primMST(int g[V][V]) {
    int parent[V], key[V]; bool mstSet[V];
    for (int i = 0; i < V; i++) key[i] = INT_MAX, mstSet[i] = 0;
    key[0] = 0, parent[0] = -1;
    for (int c = 0; c < V - 1; c++) {
        int u = minKey(key, mstSet); mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (g[u][v] && !mstSet[v] && g[u][v] < key[v]) parent[v] = u, key[v] = g[u][v];
    }
    int total = 0;
    std::cout << "Edge\tDist\n";
    for (int i = 1; i < V; i++) std::cout << homes[parent[i]] << "-" << homes[i] << "\t" << g[i][parent[i]] << "\n", total += g[i][parent[i]];
    std::cout << "Total pipe length = " << total << " meters\n";
}
int main() {
    int g[V][V] = {
        {0,5,0,4,0},
        {5,0,7,9,0},
        {0,7,0,9,5},
        {4,9,9,0,8},
        {0,0,5,8,0}
    };
    primMST(g);
    return 0;
}
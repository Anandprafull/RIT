#include <iostream>
#include <vector>
#define INF 99999
#define V 5
using namespace std;

const char* home[V] = {"a","b","c","d","e"};
// Adjacency list: pair<neighbor, weight>
vector<pair<int, int>> adj[V] = {
    { {1,5}, {3,4} },      // a
    { {0,5}, {2,7}, {3,9} }, // b
    { {1,7}, {3,9}, {4,5} }, // c
    { {0,4}, {1,9}, {2,9}, {4,8} }, // d
    { {2,5}, {3,8} }      // e
};
void primMST() {
    int parent[V], key[V]; 
    bool inMST[V];
    for (int i = 0; i < V; i++) 
        key[i] = INF, inMST[i] = false, parent[i] = -1;
    key[0] = 0; parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int minKey = INF, u = -1;
        for (int v = 0; v < V; v++) 
            if (!inMST[v] && key[v] < minKey) 
                minKey = key[v], u = v;
        inMST[u] = true;
        for (auto &edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (!inMST[v] && w < key[v])
                key[v] = w, parent[v] = u;
        }
    }
    cout << "Minimum Spanning Tree Edges:\n";
    int totalWeight = 0;
    for (int i = 0; i < V; i++) 
        if (parent[i] != -1) { 
            cout << home[parent[i]] << " - " << home[i] << " : " << key[i] << "m\n";
            totalWeight += key[i];
        }
    cout << "Total length of pipe required: " << totalWeight << "m\n";
}
int main() {
    primMST();
    return 0;
}
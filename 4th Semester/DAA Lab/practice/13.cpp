#include <iostream>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, w; // u: source vertex, v: destination vertex, w: weight
};

// Comparator function to sort edges by weight
bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

// Disjoint Set Union (Union-Find) data structure for cycle detection
class DSU {
    int parent[100], rank[100]; // parent and rank arrays for DSU
public:
    // Initialize DSU for n elements
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    // Find the representative (root) of the set containing x
    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
    // Union the sets containing x and y
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr != yr) {
            if (rank[xr] < rank[yr]) parent[xr] = yr;
            else if (rank[xr] > rank[yr]) parent[yr] = xr;
            else parent[yr] = xr, rank[xr]++;
        }
    }
};

// Function to sort edges using Bubble Sort
void sortEdges(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge t = edges[j]; edges[j] = edges[j + 1]; edges[j + 1] = t;
            }
}

// Kruskal's algorithm to find the cost of the Minimum Spanning Tree (MST)
int kruskal(int n, Edge edges[], int m) {
    sortEdges(edges, m); // Sort edges by weight
    DSU dsu(n); // Create DSU for n vertices
    int cost = 0;
    for (int i = 0; i < m; i++) {
        // If adding this edge doesn't form a cycle
        if (dsu.find(edges[i].u) != dsu.find(edges[i].v)) {
            dsu.unite(edges[i].u, edges[i].v); // Union the sets
            cost += edges[i].w; // Add edge weight to total cost
        }
    }
    return cost;
}

int main() {
    int n = 4, m = 5;
    // Define the edges of the graph: {u, v, w}
    Edge edges[5] = {{0, 1, 1}, {1, 2, 2}, {0, 2, 3}, {2, 3, 4}, {1, 3, 5}};

    // Print the cost of the Minimum Spanning Tree
    cout << "Minimum Cost Spanning Tree: " << kruskal(n, edges, m) << endl;
    return 0;
}
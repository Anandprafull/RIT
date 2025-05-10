#include <iostream>
#include <cstring> // For memset
using namespace std;

int main() {
    // n is the number of vertices
    // m is the number of edges
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Declare and initialize the adjacency matrix
    int adjMat[n][n];
    memset(adjMat, 0, sizeof(adjMat)); // Initialize all elements to 0

    // Input edges
    cout << "Enter the edges (u v) one by one:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1; // Mark the edge from u to v
        adjMat[v][u] = 1; // Mark the edge from v to u (for undirected graph)
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) { // Use 0-based indexing
        for (int j = 0; j < n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
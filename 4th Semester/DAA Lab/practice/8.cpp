/* Prim's MST

function minKey(key, mstSet):
    min = ∞
    min_index = -1
    for v = 0 to V-1:
        if not mstSet[v] and key[v] < min:
            min = key[v]
            min_index = v
    return min_index

function printMST(parent, graph):
    totalWeight = 0
    for i = 1 to V-1:
        print parent[i], "-", i, "Weight:", graph[i][parent[i]]
        totalWeight += graph[i][parent[i]]
    print "Total Pipe Length:", totalWeight

function primMST(graph, start):
    parent = array of size V, initialized to -1
    key = array of size V, initialized to ∞
    mstSet = array of size V, initialized to false

    key[start] = 0

    for count = 0 to V-2:
        u = minKey(key, mstSet)
        mstSet[u] = true

        for v = 0 to V-1:
            if graph[u][v] and not mstSet[v] and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]

    printMST(parent, graph)

main:
    define graph as adjacency matrix
    primMST(graph, startVertex)

    Complexity Analysis
Time Complexity: O(V²)
    The outer loop runs V times.
    The minKey function is called V times and each call scans all V vertices.
    The inner loop for updating keys also runs V times per outer iteration.
Space Complexity: O(V²)
    For the adjacency matrix representation of the graph.
    Additional O(V) space for parent, key, and mstSet arrays.
This is the standard implementation of Prim's algorithm using an adjacency matrix.
*/


#include <iostream>
#include <climits>

using namespace std;

#define V 6  // Number of vertices

// Returns the index of the vertex not yet included in MST with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Prints the MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    int totalWeight = 0;
    cout << "Edges in MST:\n";

    for (int i = 0; i < V; i++) {
        if (parent[i] != -1) {
            char from = 'A' + parent[i];
            char to = 'A' + i;
            int weight = graph[i][parent[i]];
            cout << from << " - " << to << "  Weight: " << weight << "\n";
            totalWeight += weight;
        }
    }
    cout << "Total Pipe Length: " << totalWeight << " meters\n";
}

// Implements Prim's algorithm to construct MST starting from 'start'
void primMST(int graph[V][V], int start) {
    int parent[V];  
    int key[V];    
    bool mstSet[V]; 

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[start] = 0; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {  0,  5,  2,  6,  0,  0},   // A
        {  5,  0,  2,  0,  0,  0},   // B
        {  2,  2,  0,  0,  3,  0},   // C
        {  6,  0,  0,  0,  3,  7},   // D
        {  0,  0,  3,  3,  0,  8},   // E
        {  0,  0,  0,  7,  8,  0}    // F
    };

    int startVertex = 5; // Start from 'F'
    primMST(graph, startVertex);

    return 0;
}
#include <iostream>
#include <climits>
#include <ctime>

#define V 5 // Number of mobile homes

const char* mobileHomes[V] = {"A", "B", "C", "D", "E"};

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST and total pipe length
void printMST(int parent[], int graph[V][V]) {
    int totalLength = 0;
    std::cout << "Edge \tDistance (meters)\n";
    for (int i = 1; i < V; i++) {
        std::cout << mobileHomes[parent[i]] << " - " << mobileHomes[i] 
                  << "\t" << graph[i][parent[i]] << "\n";
        totalLength += graph[i][parent[i]];
    }
    std::cout << "Total pipe length needed = " << totalLength << " meters\n";
}

// Function implementing Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the MST
    int key[V];    // Array to store the minimum edge weights
    bool mstSet[V]; // Array to track visited nodes

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

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
        {0, 5, 0, 4, 0},  // A
        {5, 0, 7, 9, 0},  // B
        {0, 7, 0, 9, 5},  // C
        {4, 9, 9, 0, 8},  // D
        {0, 0, 5, 8, 0}   // E
    };

    clock_t start = clock();
    primMST(graph);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Convert to milliseconds
    std::cout << "\nTime taken: " << time_taken << " ms\n";

    return 0;
}
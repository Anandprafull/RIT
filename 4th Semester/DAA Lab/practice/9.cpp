#include <iostream>
#include <climits>
#include <ctime>

#define V 6  // Number of locations
const char* locations[V] = {"Location 1", "Location 2", "Location 3", "Location 4", "Location 5", "Location 6"};

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

void printMST(int parent[], int graph[V][V]) {
    int totalCost = 0;
    std::cout << "Optimal Driving Route:\n";
    for (int i = 1; i < V; i++) {
        std::cout << locations[parent[i]] << " -> " << locations[i] 
                  << " (" << graph[i][parent[i]] << " km)\n";
        totalCost += graph[i][parent[i]];
    }
    std::cout << "Total Minimum Driving Cost: " << totalCost << " km\n";
}

void primMST(int graph[V][V], int start) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[start] = 0;  
    parent[start] = -1;

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
        {0, 10, 0, 30, 0, 25},  
        {10, 0, 20, 0, 0, 0},  
        {0, 20, 0, 0, 15, 0},  
        {30, 0, 0, 0, 0, 10},  
        {0, 0, 15, 0, 0, 5},  
        {25, 0, 0, 10, 5, 0}  
    };

    int startLocation = 0;  // Choose any arbitrary location

    clock_t start = clock();
    primMST(graph, startLocation);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    std::cout << "Execution Time: " << time_taken << " ms\n";

    return 0;
}
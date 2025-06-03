#include <iostream>
#include <climits>
#include <ctime>

#define V 6 // Number of cities

const char* cities[V] = {"San Francisco", "Los Angeles", "Denver", "Chicago", "Boston", "New York"};

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest distances from source
void printSolution(int dist[]) {
    std::cout << "Shortest distances from San Francisco:\n";
    for (int i = 0; i < V; i++) {
        std::cout << cities[i] << ": " << dist[i] << " km\n";
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // Distance from source to itself is zero

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 600, 1200, 2100, 3000, 3200},  // San Francisco
        {600, 0, 1400, 2000, 2900, 3100},  // Los Angeles
        {1200, 1400, 0, 1000, 1900, 2100}, // Denver
        {2100, 2000, 1000, 0, 1000, 800},  // Chicago
        {3000, 2900, 1900, 1000, 0, 300},  // Boston
        {3200, 3100, 2100, 800, 300, 0}    // New York
    };

    clock_t start = clock();
    dijkstra(graph, 0);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Convert to milliseconds
    std::cout << "\nTime taken: " << time_taken << " ms\n";

    return 0;
}
/*
function Dijkstra(graph, source):
    dist[] = array of size V, initialized to infinity
    visited[] = array of size V, initialized to false
    parent[] = array of size V, initialized to -1

    dist[source] = 0

    repeat (V-1) times:
        u = vertex with minimum dist[] value among unvisited vertices
        visited[u] = true

        for each vertex v adjacent to u:
            if not visited[v] and graph[u][v] != 0:
                if dist[u] + graph[u][v] < dist[v]:
                    dist[v] = dist[u] + graph[u][v]
                    parent[v] = u

    // Output shortest distances and paths
    for each vertex i:
        print dist[i]
        print path from source to i using parent[]
        
    */

#include <iostream>
#include <climits>
#include <ctime>

#define V 7 // Number of cities

const char* cities[V] = {
        "SF", "LA", "Denver", "Dallas", "Chicago", "NY", "Boston"
};

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest path from src to target using parent[]
void printPath(int parent[], int target) {
    if (parent[target] == -1) {
        std::cout << cities[target];
        return;
    }
    printPath(parent, parent[target]);
    std::cout << " -> " << cities[target];
}

// Dijkstra's algorithm implementation with path reconstruction
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0; // Distance from source to itself is zero

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    std::cout << "Shortest response times from San Francisco:\n";
    for (int i = 0; i < V; i++) {
        std::cout << "  To " << cities[i] << ": ";
        if (dist[i] == INT_MAX)
            std::cout << "No path\n";
        else
            std::cout << dist[i] << " sec\n";
    }

    // Print shortest path from SF to New York
    int target = 5; // New York
    std::cout << "\nShortest path to New York:\n";
    if (dist[target] == INT_MAX) {
        std::cout << "  No path from San Francisco to New York.\n";
    } else {
        printPath(parent, target);
        std::cout << "\nTotal: " << dist[target] << " sec\n";
    }
}

int main() {
    // Adjacency matrix for Fig. 4b (undirected)
    // 0=SF,1=LA,2=Denver,3=Dallas,4=Chicago,5=NY,6=Boston
    int graph[V][V] = {
        {0,3,4,5,0,0,0},  // SF
        {3,0,7,5,0,0,0},  // LA
        {4,7,0,4,6,0,0},  // Denver
        {5,5,4,0,5,6,0},  // Dallas
        {0,0,6,5,0,4,3},  // Chicago
        {0,0,0,6,4,0,2},  // NY
        {0,0,0,0,3,2,0}   // Boston
    };
    clock_t start = clock();
    dijkstra(graph, 0);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "\nTime taken: " << time_taken << " seconds\n";
    std::cout << "Time Complexity: O(V^2)\n";
    return 0;
}

/*
#include <iostream>
#include <climits>
#define V 7
const char* cities[V] = {"SF", "LA", "Denver", "Dallas", "Chicago", "NY", "Boston"};

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, idx = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] < min) min = dist[v], idx = v;
    return idx;
}

void printPath(int parent[], int t) {
    if (parent[t] != -1) { printPath(parent, parent[t]); std::cout << " -> "; }
    std::cout << cities[t];
}

void dijkstra(int g[V][V], int src) {
    int dist[V], parent[V]; bool vis[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, vis[i] = false, parent[i] = -1;
    dist[src] = 0;
    for (int c = 0; c < V - 1; c++) {
        int u = minDistance(dist, vis); if (u == -1) break; vis[u] = true;
        for (int v = 0; v < V; v++)
            if (!vis[v] && g[u][v] && dist[u] != INT_MAX && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v], parent[v] = u;
    }
    std::cout << "Shortest response times from SF:\n";
    for (int i = 0; i < V; i++)
        std::cout << "  To " << cities[i] << ": " << (dist[i] == INT_MAX ? "No path" : std::to_string(dist[i]) + " sec") << "\n";
    int target = 5;
    std::cout << "\nShortest path to NY:\n";
    if (dist[target] == INT_MAX) std::cout << "  No path from SF to NY.\n";
    else { printPath(parent, target); std::cout << "\nTotal: " << dist[target] << " sec\n"; }
}

int main() {
    int graph[V][V] = {
        {0,3,4,5,0,0,0},{3,0,7,5,0,0,0},{4,7,0,4,6,0,0},
        {5,5,4,0,5,6,0},{0,0,6,5,0,4,3},{0,0,0,6,4,0,2},{0,0,0,0,3,2,0}
    };
    dijkstra(graph, 0);
    return 0;
}*/

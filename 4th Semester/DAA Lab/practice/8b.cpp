#include <iostream>
#include <algorithm>
#include <ctime>

#define V 7  
#define E 9  

struct Edge {
    int src, dest, weight;
};

void printMST(Edge result[], int n) {
    int totalWeight = 0;
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < n; i++) {
        std::cout << result[i].src << " - " << result[i].dest << " (" << result[i].weight << ")\n";
        totalWeight += result[i].weight;
    }
    std::cout << "Total Minimum Cost: " << totalWeight << "\n";
}

int findParent(int parent[], int i) {
    return (parent[i] == i) ? i : findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(Edge edges[]) {
    std::sort(edges, edges + E, [](Edge a, Edge b) { return a.weight < b.weight; });

    Edge result[V - 1];  
    int parent[V], rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int edgeCount = 0, i = 0;
    while (edgeCount < V - 1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y) {
            result[edgeCount++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    printMST(result, edgeCount);
}

void kruskalMST(Edge edges[]); // Function prototype

int main() {
    Edge edges[E] = {
        {0, 5, 10}, {0, 1, 28}, {1, 2, 16}, {2, 3, 12}, {3, 4, 22}, {4, 5, 25},
        {1, 6, 14}, {6, 3, 18}, {6, 4, 24}
    };

    clock_t start = clock();
    kruskalMST(edges);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    std::cout << "Execution Time: " << time_taken << " ms\n";

    return 0;
}
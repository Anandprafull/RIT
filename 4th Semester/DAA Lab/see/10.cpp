#include <bits/stdc++.h>
using namespace std;
#define V 7

const char *cities[V] = {"SF", "LA", "Denver", "Dallas", "Chicago", "NY", "Boston"};

int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX, idx = -1;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] < min)
            min = dist[v], idx = v;
    }
    return idx;
}

void dijikstra(int graph[V][V], int src)
{
    int dist[V], parent[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false, parent[i] = -1;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        if (u == -1)
            break;
        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v], parent[v] = u;
    }
    int target = 5;
    cout << "Shortest Time to NY: ";
    if (dist[target] == INT_MAX)
        cout << "NoPath\n";
    else
        cout << "Shortest distances from San Francisco:\n";
        for (int i = 0; i < V; i++) 
            cout << cities[i] << ": " << dist[i] << " s\n";
}

int main()
{
    int graph[V][V] = {
        {0, 3, 4, 5, 0, 0, 0},
        {3, 0, 7, 5, 0, 0, 0},
        {4, 7, 0, 4, 6, 0, 0},
        {5, 5, 4, 0, 5, 6, 0},
        {0, 0, 6, 5, 0, 4, 3},
        {0, 0, 0, 6, 4, 0, 2},
        {0, 0, 0, 0, 3, 2, 0}};
    dijikstra(graph, 0);
    return 0;
}
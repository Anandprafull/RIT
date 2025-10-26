#include <iostream>
#include <queue>
#include <time.h>
using namespace std;

int a[100][100], s[100], v[100], p[100], V;

int main()
{
    int E;
    cout << "Vertices, edges: ";
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, w;
        cin >> u >> w;
        a[u][s[u]++] = w;
        a[w][s[w]++] = u;
    }

    fill(p, p + V, -1);
    queue<int> q;
    q.push(0);
    v[0] = 1;
    clock_t t = clock();
    cout << "BFS: 0 ";

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < s[u]; i++)
        {
            int w = a[u][i];
            if (!v[w])
            {
                v[w] = 1;
                p[w] = u;
                q.push(w);
                cout << w << " ";
            }
        }
    }

    cout << "\nTree:\n";
    for (int i = 1; i < V; i++)
        if (p[i] != -1)
            cout << p[i] << "->" << i << "\n";
    cout << "Time: " << double(clock() - t) / CLOCKS_PER_SEC * 1e9 << " ns\n";
}
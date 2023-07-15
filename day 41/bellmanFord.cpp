#include <bits/stdc++.h>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    bool flag = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
        {
            flag = true;
        }
    }
    if (flag)
        return -1;
    return dist[dest];
}
int main()
{
    vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}};
    cout << "Bellman-Ford Algorithm: " << bellmonFord(4, 4, 1, 4, edges);
}
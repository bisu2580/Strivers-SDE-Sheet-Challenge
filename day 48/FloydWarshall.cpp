#include <bits/stdc++.h>
using namespace std;
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    map<int, vector<pair<int, int>>> adjList;
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (auto it : edges)
    {
        int u = it[0] - 1;
        int v = it[1] - 1;
        int wt = it[2];
        dist[u][v] = wt;
    }
    for (int helper = 0; helper < n; helper++)
    {
        for (int src = 0; src < n; src++)
        {
            for (int dest = 0; dest < n; dest++)
            {
                if (dist[src][helper] != 1e9 && dist[helper][dest] != 1e9)
                    dist[src][dest] = min(dist[src][dest], (dist[src][helper] + dist[helper][dest]));
            }
        }
    }
    return dist[src - 1][dest - 1];
}
int main()
{
    vector<vector<int>> edges = {{1, 2, 2}, {1, 3, 2}, {2, 3, -1}};
    cout << floydWarshall(3, 3, 1, 3, edges) << endl;
}
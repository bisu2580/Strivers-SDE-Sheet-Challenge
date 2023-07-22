#include <bits/stdc++.h>
using namespace std;
void makeAdj(vector<vector<int>> &edges, map<int, vector<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[0].size(); j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    map<int, vector<int>> adj;
    makeAdj(edges, adj);
    queue<int> q;
    q.push(0);
    int v = edges.size();
    vector<int> color(v);

    for (int i = 0; i < v; i++)
        color[i] = -1;

    color[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> edges = {{0, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    cout << isGraphBirpatite(edges);
}
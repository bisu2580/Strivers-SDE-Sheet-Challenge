#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &temp, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, int node)
{
    temp.push_back(node);
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(temp, adj, visited, neighbour);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;

    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            dfs(temp, adj, visited, i);
            ans.push_back(temp);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    vector<vector<int>> ans = depthFirstSearch(5, 4, edges);
    cout << "Depth First Traversal: \n";
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
void makeList(vector<vector<int>> &edges, unordered_map<int, vector<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
}
void dfs(int node, stack<int> &ans, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, ans, adj, visited);
        }
    }
    ans.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(v, false);
    stack<int> ans;
    makeList(edges, adj);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, ans, adj, visited);
        }
    }

    vector<int> num;
    while (!ans.empty())
    {
        num.push_back(ans.top());
        ans.pop();
    }
    return num;
}
int main()
{
}
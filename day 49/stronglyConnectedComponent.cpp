#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> adjList[], vector<bool> &visited, stack<int> &s)
{
    visited[src] = true;
    for (auto nbr : adjList[src])
    {
        if (!visited[nbr])
        {
            dfs(nbr, adjList, visited, s);
        }
    }
    s.push(src);
}
void dfs2(int src, vector<int> adj[], vector<bool> &visited, vector<int> &temp)
{
    visited[src] = true;
    temp.push_back(src);
    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            dfs2(nbr, adj, visited, temp);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adjList[n], adjNew[n];
    // Make adjacent list
    for (auto it : edges)
    {
        adjList[it[0]].push_back(it[1]);
    }
    // Apply DFS
    vector<bool> visited(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjList, visited, s);
        }
    }
    // Reverse edges
    vector<bool> visited2(n, false);
    for (auto it : edges)
    {
        adjNew[it[1]].push_back(it[0]);
    }
    // Apply dfs again
    vector<vector<int>> ans;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        vector<int> temp;
        if (!visited2[node])
        {
            dfs2(node, adjNew, visited2, temp);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {2, 3}, {3, 2}, {4, 0}};
    auto res = stronglyConnectedComponents(5, edges);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
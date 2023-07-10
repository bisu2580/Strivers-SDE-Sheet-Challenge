#include <bits/stdc++.h>
using namespace std;
void adjListBuild(unordered_map<int, set<int>> &adj, vector<pair<int, int>> edges)
{
    for (auto e : edges)
    {
        auto u = e.first;
        auto v = e.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}
void bfs(unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (visited[f])
            continue;
        visited[f] = true;
        ans.push_back(f);
        for (auto neighbour : adj[f])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;
    adjListBuild(adj, edges);

    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(visited, adj, ans, i);
        }
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> edges = {{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};
    vector<int> ans = BFS(4, edges);
    cout << "Breadth First Traversal: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
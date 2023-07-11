#include <bits/stdc++.h>
using namespace std;
void buildList(vector<vector<int>> &edges, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
bool solve(int node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited)
{
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto neighbour : adjList[curr])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = curr;
            }
            else
            {
                if (neighbour != parent[curr])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;
    buildList(edges, adjList);
    string answer = "No";
    bool ans;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            ans = solve(i, adjList, visited);
        if (ans)
            answer = "Yes";
    }
    return answer;
}
int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << cycleDetection(edges, 5, 5).data();
}
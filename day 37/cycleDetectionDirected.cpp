#include <bits/stdc++.h>
using namespace std;
void makeList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (auto i : edges)
    {
        int u = i.first;
        int v = i.second;
        adjList[u].insert(v);
    }
}
bool check(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, set<int>> &adjList)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto nbr : adjList[node])
    {
        if (!visited[nbr])
        {
            bool aage = check(nbr, visited, dfsVisited, adjList);
            if (aage)
                return true;
        }
        if (visited[nbr] && dfsVisited[nbr])
            return true;
    }
    dfsVisited[node] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    unordered_map<int, set<int>> adjList;
    makeList(adjList, edges);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = check(i, visited, dfsVisited, adjList);
        }
        if (ans)
            break;
    }
    if (ans)
        return 1;
    return 0;
}
int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << detectCycleInDirectedGraph(5, edges);
}
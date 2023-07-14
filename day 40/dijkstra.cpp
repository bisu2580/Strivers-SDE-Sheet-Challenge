#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        auto top = *(st.begin());
        int distance = top.first;
        int node = top.second;
        st.erase(st.begin());

        for (auto nbr : adj[node])
        {
            if (distance + nbr.second < dist[nbr.first])
            {
                auto record = st.find(make_pair(dist[nbr.first], nbr.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                dist[nbr.first] = distance + nbr.second;
                st.insert(make_pair(dist[nbr.first], nbr.first));
            }
        }
    }
    return dist;
}
int main()
{
}
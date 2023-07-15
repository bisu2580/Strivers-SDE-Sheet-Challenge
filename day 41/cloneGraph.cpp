#include <bits/stdc++.h>
using namespace std;
class graphNode
{
public:
    int data;
    vector<graphNode *> neighbours;
    graphNode()
    {
        data = 0;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val)
    {
        data = val;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val, vector<graphNode *> neighbours)
    {
        data = val;
        this->neighbours = neighbours;
    }
};
graphNode *dfs(graphNode *&node, unordered_map<graphNode *, graphNode *> &adj)
{
    vector<graphNode *> neighbour;
    graphNode *root = new graphNode(node->data);
    adj[node] = root;
    for (auto nbr : node->neighbours)
    {
        if (adj.find(nbr) != adj.end())
        {
            neighbour.push_back(adj[nbr]);
        }
        else
        {
            neighbour.push_back(dfs(nbr, adj));
        }
    }
    root->neighbours = neighbour;
    return root;
}
graphNode *cloneGraph(graphNode *node)
{
    unordered_map<graphNode *, graphNode *> adj;
    if (!node)
        return NULL;
    if (node->neighbours.size() == 0)
    {
        graphNode *clone = new graphNode(node->data);
        return clone;
    }
    return dfs(node, adj);
}
int main()
{
}
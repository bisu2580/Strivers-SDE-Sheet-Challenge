#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> mp;

    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {

        pair<TreeNode<int> *, int> f = q.front();
        q.pop();
        TreeNode<int> *frontNode = f.first;
        int dist = f.second;

        if (mp.find(dist) == mp.end())
        {
            mp[dist] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push({frontNode->left, dist - 1});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right, dist + 1});
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *a = new TreeNode<int>(2);
    TreeNode<int> *b = new TreeNode<int>(3);
    TreeNode<int> *c = new TreeNode<int>(4);
    TreeNode<int> *d = new TreeNode<int>(5);
    TreeNode<int> *e = new TreeNode<int>(6);
    TreeNode<int> *f = new TreeNode<int>(7);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    vector<int> ans = getTopView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
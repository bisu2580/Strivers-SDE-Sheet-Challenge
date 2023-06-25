#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
vector<int> bottomView(BinaryTreeNode<int> *root)
{

    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> mp;

    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {

        pair<BinaryTreeNode<int> *, int> f = q.front();
        q.pop();
        BinaryTreeNode<int> *frontNode = f.first;
        int dist = f.second;

        mp[dist] = frontNode->data;

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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *a = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *b = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *c = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *d = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int> *e = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int> *f = new BinaryTreeNode<int>(7);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    vector<int> ans = bottomView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
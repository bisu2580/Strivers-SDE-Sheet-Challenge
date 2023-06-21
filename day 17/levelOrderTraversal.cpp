#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    vector<int> ans;
    if (!root)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        ans.push_back(temp->val);
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
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
    root->left = a;
    root->right = b;
    a->left = c;
    c->right = d;
    vector<int> v = getLevelOrder(root);
    for (auto i : v)
    {
        cout << i << " ";
    }
}
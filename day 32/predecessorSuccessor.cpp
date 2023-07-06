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
int predecessor(TreeNode<int> *root, int x)
{
    int ans = -1;
    while (root)
    {
        if (x > root->data)
        {
            ans = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}
int successor(TreeNode<int> *root, int x)
{
    int ans = -1;
    while (root)
    {
        if (x < root->data)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}
pair<int, int> predecessorSuccessor(TreeNode<int> *root, int key)
{
    pair<int, int> p{-1, -1};
    p.first = predecessor(root, key);
    p.second = successor(root, key);
    return p;
}
int main()
{
}
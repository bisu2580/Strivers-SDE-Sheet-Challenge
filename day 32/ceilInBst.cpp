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
int findCeil(TreeNode<int> *node, int x)
{
    int ans = -1;
    while (node)
    {
        if (x == node->data)
        {
            ans = node->data;
            return ans;
        }
        if (x < node->data)
        {
            ans = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return ans;
}
int main()
{
}
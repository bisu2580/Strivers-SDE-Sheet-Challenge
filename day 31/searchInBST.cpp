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
bool searchInBST(TreeNode<int> *root, int x)
{
    if (!root)
        return false;
    if (root->data == x)
        return true;
    if (x > root->data)
        return searchInBST(root->right, x);
    return searchInBST(root->left, x);
}
int main()
{
}
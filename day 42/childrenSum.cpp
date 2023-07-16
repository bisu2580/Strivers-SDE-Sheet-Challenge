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
void changeTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);

    int ans = 0;
    if (root->left)
        ans += root->left->data;
    if (root->right)
        ans += root->right->data;
    if (root->left || root->right)
        root->data = ans;
}
int main()
{
}
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
TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (!root)
        return NULL;
    if (p->data < root->data && q->data < root->data)
    {
        return LCAinaBST(root->left, p, q);
    }
    if (p->data > root->data && q->data > root->data)
    {
        return LCAinaBST(root->right, p, q);
    }
    return root;
}
int main()
{
}
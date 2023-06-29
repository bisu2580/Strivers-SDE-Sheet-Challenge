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

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode<int> *pred = curr->left;
            while (pred->right)
                pred = pred->right;
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
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
    root = flattenBinaryTree(root);
}
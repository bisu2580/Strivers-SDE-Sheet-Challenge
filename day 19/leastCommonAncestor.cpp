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
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if (root == NULL)
        return -1;
    if (root->data == x || root->data == y)
        return root->data;

    int leftPart = lowestCommonAncestor(root->left, x, y);
    int rightPart = lowestCommonAncestor(root->right, x, y);

    if (leftPart != -1 && rightPart != -1)
        return root->data;
    return max(leftPart, rightPart);
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
    cout << "LCA of 6 and 7 is " << lowestCommonAncestor(root, 6, 7);
}
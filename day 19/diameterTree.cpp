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
int getHeight(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    int ans = max(lh, rh) + 1;
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    if (!root)
        return 0;

    int leftTree = diameterOfBinaryTree(root->left);
    int rightTree = diameterOfBinaryTree(root->right);
    int heightThroughRoots = getHeight(root->left) + getHeight(root->right);

    return max(leftTree, max(rightTree, heightThroughRoots));
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
    cout << "Diameter is " << diameterOfBinaryTree(root);
}
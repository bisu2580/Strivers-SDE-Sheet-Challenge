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
void boundryOrderRight(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    if (root->right)
    {
        boundryOrderRight(root->right, ans);
    }
    else
    {
        boundryOrderRight(root->left, ans);
    }
    ans.push_back(root->data);
}
void boundryOrderLeaf(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        ans.push_back(root->data);
    boundryOrderLeaf(root->left, ans);
    boundryOrderLeaf(root->right, ans);
}
void boundryOrderLeft(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    ans.push_back(root->data);

    if (root->left)
    {
        boundryOrderLeft(root->left, ans);
    }
    else
    {
        boundryOrderLeft(root->right, ans);
    }
}
void traversal(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    if (!root->left && !root->right)
        return;
    boundryOrderLeft(root->left, ans);
    boundryOrderLeaf(root, ans);
    boundryOrderRight(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    traversal(root, ans);
    return ans;
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
    cout << "The boundary of the tree is: ";
    vector<int> ans = traverseBoundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
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
bool solve(vector<int> &ans, TreeNode<int> *root, int x)
{
    if (!root)
    {
        return false;
    }
    if (root->data == x)
    {
        ans.push_back(x);
        return true;
    }
    if (root->left || root->right)
    {
        if (solve(ans, root->left, x) || solve(ans, root->right, x))
        {
            ans.push_back(root->data);
            return true;
        }
    }
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    solve(ans, root, x);
    reverse(ans.begin(), ans.end());
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
    cout << "path in tree: ";
    vector<int> ans = pathInATree(root, 6);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
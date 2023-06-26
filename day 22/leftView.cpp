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
void solve(TreeNode<int> *root, vector<int> &ans, int levelCount)
{
    if (!root)
        return;

    if (levelCount == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, levelCount + 1);
    solve(root->right, ans, levelCount + 1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    int levelCount = 0;
    solve(root, ans, levelCount);
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
    cout << "The Left View of the given tree is : ";
    vector<int> ans = getLeftView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
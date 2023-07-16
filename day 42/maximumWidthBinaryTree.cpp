#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
void bfs(TreeNode<int> *root, unordered_map<int, vector<int>> &mp, int &level)
{
    if (!root)
        return;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto fNode = q.front();
        q.pop();
        auto node = fNode.first;
        auto level = fNode.second;
        mp[level].push_back(node->val);
        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
}
int getMaxWidth(TreeNode<int> *root)
{
    if (!root)
        return 0;
    unordered_map<int, vector<int>> mp;
    int start = 0;
    bfs(root, mp, start);
    int maxWidth = INT_MIN;
    for (auto it : mp)
    {
        int n = it.second.size();
        maxWidth = max(maxWidth, n);
    }
    return maxWidth;
}
int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->right->left = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(6);
    root->left->left->right = new TreeNode<int>(7);
    cout << "Maximum Width: " << getMaxWidth(root) << endl;
}
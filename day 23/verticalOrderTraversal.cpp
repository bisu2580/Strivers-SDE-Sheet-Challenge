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
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<pair<TreeNode<int> *, int>> q;
    map<int, vector<int>> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto frontNode = q.front();
        q.pop();
        TreeNode<int> *node = frontNode.first;
        int line = frontNode.second;
        mp[line].emplace_back(node->data);

        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto i : mp)
    {
        vector<int> nums = i.second;
        ans.insert(ans.end(), nums.begin(), nums.end());
    }
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
    vector<int> nums = verticalOrderTraversal(root);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}
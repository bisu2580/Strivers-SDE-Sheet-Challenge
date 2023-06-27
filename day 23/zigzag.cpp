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

vector<int> solve(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push({root});

    bool leftToRight = true;

    while (!q.empty())
    {
        int width = q.size();
        vector<int> temp(width);
        for (int i = 0; i < width; i++)
        {
            auto frontElement = q.front();
            q.pop();
            int index = leftToRight ? i : width - i - 1;
            temp[index] = frontElement->data;
            if (frontElement->left)
            {
                q.push(frontElement->left);
            }
            if (frontElement->right)
            {
                q.push(frontElement->right);
            }
        }
        leftToRight = !leftToRight;
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    ans = solve(root, ans);
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *a = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *b = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *c = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *d = new BinaryTreeNode<int>(5);
    BinaryTreeNode<int> *e = new BinaryTreeNode<int>(6);
    BinaryTreeNode<int> *f = new BinaryTreeNode<int>(7);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    vector<int> nums = zigZagTraversal(root);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}
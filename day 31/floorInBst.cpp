#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};
int floorInBST(TreeNode<int> *root, int x)
{
    int ans = -1;
    while (root)
    {
        if (root->val == x)
        {
            ans = root->val;
            return ans;
        }
        if (x > root->val)
        {
            ans = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return ans;
}
int main()
{
}
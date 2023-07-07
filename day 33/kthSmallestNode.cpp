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
int kthSmallest(TreeNode<int> *root, int &k)
{
    if (!root)
        return -1;

    int leftAns = kthSmallest(root->left, k);
    if (leftAns != -1)
        return leftAns;

    k--;
    if (k == 0)
        return root->data;

    int rightAns = kthSmallest(root->right, k);
    return rightAns;
}
int main()
{
}
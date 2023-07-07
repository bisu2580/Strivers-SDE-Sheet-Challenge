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
int KthLargestNumber(TreeNode<int> *root, int &k)
{
    if (!root)
        return -1;

    int rightAns = KthLargestNumber(root->right, k);
    if (rightAns != -1)
        return rightAns;

    k--;
    if (k == 0)
        return root->data;
    int leftAns = KthLargestNumber(root->left, k);
    return leftAns;
}
int main()
{
}
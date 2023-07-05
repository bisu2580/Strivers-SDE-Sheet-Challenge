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
TreeNode<int> *solve(vector<int> &arr, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode<int> *root = new TreeNode<int>(arr[mid]);

    root->left = solve(arr, start, mid - 1);
    root->right = solve(arr, mid + 1, end);

    return root;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    TreeNode<int> *root = solve(arr, 0, n - 1);
    return root;
}
int main()
{
}
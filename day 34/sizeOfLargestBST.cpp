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
class NodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool valid;
    NodeData()
    {
    }
    NodeData(int size, int maxi, int mini, bool valid)
    {
        this->size = size;
        maxVal = maxi;
        minVal = mini;
        this->valid = valid;
    }
};
NodeData findLargest(TreeNode<int> *root, int &ans)
{
    if (!root)
    {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }
    NodeData leftAns = findLargest(root->left, ans);
    NodeData rightAns = findLargest(root->right, ans);

    NodeData curr;

    curr.size = leftAns.size + rightAns.size + 1;
    curr.maxVal = max(root->data, rightAns.maxVal);
    curr.minVal = min(root->data, leftAns.minVal);

    if (leftAns.valid && rightAns.valid && (root->data > leftAns.maxVal && root->data < rightAns.minVal))
    {
        curr.valid = true;
    }
    else
    {
        curr.valid = false;
    }
    if (curr.valid)
    {
        ans = max(ans, curr.size);
    }
    return curr;
}
int largestBST(TreeNode<int> *root)
{
    int ans = 0;
    findLargest(root, ans);
    return ans;
}
int main()
{
}
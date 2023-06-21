#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};
pair<bool, int> isBalanced(BinaryTreeNode<int> *root)
{
    if (!root)
        return {true, 0};

    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return isBalanced(root).first;
}
int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *a = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *b = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *c = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *d = new BinaryTreeNode<int>(5);
    root->left = a;
    root->right = b;
    a->left = c;
    c->right = d;
    cout << boolalpha;
    cout << isBalancedBT(root);
}
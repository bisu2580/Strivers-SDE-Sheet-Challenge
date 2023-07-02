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
bool path(TreeNode<int> *root, stack<TreeNode<int> *> &st, TreeNode<int> *leaf)
{

    st.push(root);

    if (!root->left && !root->right)
    {
        if (root->data == leaf->data)
        {
            return true;
        }
        else
        {
            st.pop();
            return false;
        }
    }

    if (root->left)
    {
        if (path(root->left, st, leaf))
        {
            return true;
        }
    }

    if (root->right)
    {
        if (path(root->right, st, leaf))
        {
            return true;
        }
    }

    st.pop();
    return false;
}
TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if (!root)
        return root;

    stack<TreeNode<int> *> st;

    path(root, st, leaf);

    TreeNode<int> *newRoot = st.top();
    st.pop();

    TreeNode<int> *parent = newRoot;

    while (!st.empty())
    {
        auto curr = st.top();
        st.pop();

        if (curr->left == parent)
        {
            curr->left = NULL;
        }
        else
        {
            curr->right = curr->left;
            curr->left = NULL;
        }
        parent->left = curr;
        parent = curr;
    }
    return newRoot;
}
int main()
{
}
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
void solve(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&head)
{
    if (!root)
        return;
    solve(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    solve(root->left, head);
}
BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *head = NULL;
    solve(root, head);
    return head;
}
int main()
{
}
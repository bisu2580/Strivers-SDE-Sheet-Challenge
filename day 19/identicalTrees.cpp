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
bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{

    if (!root1 && root2)
        return false;
    if (!root2 && root1)
        return false;
    if (!root1 && !root2)
        return true;

    bool nodesEqual = (root1->data == root2->data);
    bool leftPart = identicalTrees(root1->left, root2->left);
    bool rightPart = identicalTrees(root1->right, root2->right);
    if (nodesEqual && leftPart && rightPart)
        return true;
    return false;
}
int main()
{
}
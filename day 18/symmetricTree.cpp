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
bool check(BinaryTreeNode<int> *r1, BinaryTreeNode<int> *r2)
{
    if (!r1 && r2)
        return false;
    if (!r2 && r1)
        return false;
    if (!r2 && !r1)
        return true;

    bool value = (r1->data == r2->data);
    bool leftChild = check(r1->left, r2->right);
    bool rightChild = check(r1->right, r2->left);

    return value && leftChild && rightChild;
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    return check(root->left, root->right);
}
int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *a = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *b = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *c = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *d = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *e = new BinaryTreeNode<int>(4);
    BinaryTreeNode<int> *f = new BinaryTreeNode<int>(4);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = e;
    b->left = f;
    b->right = d;
    cout << "Is symmetric: ";
    bool ans = isSymmetric(root);
    cout << ans;
}
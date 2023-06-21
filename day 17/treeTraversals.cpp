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
void inorder(BinaryTreeNode<int> *root, vector<int> &inArray)
{
    if (!root)
        return;

    inorder(root->left, inArray);
    inArray.push_back(root->data);
    inorder(root->right, inArray);
}
void preorder(BinaryTreeNode<int> *root, vector<int> &preArray)
{
    if (!root)
        return;

    preArray.push_back(root->data);
    preorder(root->left, preArray);
    preorder(root->right, preArray);
}
void postorder(BinaryTreeNode<int> *root, vector<int> &postArray)
{
    if (!root)
        return;

    postorder(root->left, postArray);
    postorder(root->right, postArray);
    postArray.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<int> inArray;
    vector<int> preArray;
    vector<int> postArray;
    vector<vector<int>> ans;

    inorder(root, inArray);
    preorder(root, preArray);
    postorder(root, postArray);

    ans = {inArray, preArray, postArray};

    return ans;
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
    vector<vector<int>> ans = getTreeTraversal(root);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

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
class BSTiterator
{
private:
    stack<TreeNode<int> *> myStack;
    void pushAll(TreeNode<int> *root)
    {
        while (root)
        {
            myStack.push(root);
            root = root->left;
        }
    }

public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int> *node = myStack.top();
        myStack.pop();
        pushAll(node->right);
        return node->data;
    }
    bool hasNext()
    {
        return !myStack.empty();
    }
};
int main()
{
}
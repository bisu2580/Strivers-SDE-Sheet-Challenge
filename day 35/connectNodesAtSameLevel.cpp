#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
void connectNodes(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *first = root;
    while (first)
    {
        BinaryTreeNode<int> *ola = first;
        BinaryTreeNode<int> *prev = NULL;
        first = NULL;
        while (ola)
        {
            if (ola->left)
            {
                if (prev)
                {
                    prev->next = ola->left;
                }
                if (!first)
                {
                    first = ola->left;
                }
                prev = ola->left;
            }
            if (ola->right)
            {
                if (prev)
                {
                    prev->next = ola->right;
                }
                if (!first)
                {
                    first = ola->right;
                }
                prev = ola->right;
            }
            ola = ola->next;
        }
    }
}
int main()
{
}
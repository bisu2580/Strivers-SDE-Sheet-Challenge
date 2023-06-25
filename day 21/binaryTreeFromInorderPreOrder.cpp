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
TreeNode<int> *buildTree(vector<int> &inorder, vector<int> &preorder, int size, int &preIndex, int start, int end, unordered_map<int, int> &mp)
{

    if (preIndex >= size || start > end)
    {
        return NULL;
    }

    int element = preorder[preIndex++];
    TreeNode<int> *root = new TreeNode<int>(element);
    int inorderPos = mp[element];
    root->left = buildTree(inorder, preorder, size, preIndex, start, inorderPos - 1, mp);
    root->right = buildTree(inorder, preorder, size, preIndex, inorderPos + 1, end, mp);
}
void print(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int size = preorder.size();
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode<int> *root = buildTree(inorder, preorder, size, preIndex, inorderStart, inorderEnd, mp);
    return root;
}
int main()
{
    vector<int> inorder = {4, 2, 7, 1, 3};
    vector<int> preorder = {1, 2, 4, 7, 3};
    TreeNode<int> *root = buildBinaryTree(inorder, preorder);
    print(root);
}
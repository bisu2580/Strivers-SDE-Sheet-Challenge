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
TreeNode<int> *buildTree(vector<int> &postOrder, vector<int> &inOrder, int size, int &postIndex, int start, int end, unordered_map<int, int> &mp)
{
    // Base Case
    if (postIndex < 0 || start > end)
    {
        return NULL;
    }

    // Find root element
    int rootElement = postOrder[postIndex--];
    // Make a root
    TreeNode<int> *root = new TreeNode<int>(rootElement);
    int rootPosInInorder = mp[rootElement];
    root->right = buildTree(postOrder, inOrder, size, postIndex, rootPosInInorder + 1, end, mp);
    root->left = buildTree(postOrder, inOrder, size, postIndex, start, rootPosInInorder - 1, mp);
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
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    int size = postOrder.size();
    int postIndex = size - 1;
    int start = 0;
    int end = size - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[inOrder[i]] = i;
    }
    return buildTree(postOrder, inOrder, size, postIndex, start, end, mp);
}
int main()
{
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};
    TreeNode<int> *result = getTreeFromPostorderAndInorder(postorder, inorder);
    print(result);
}
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}
int main()
{
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(3);
    TreeNode *third = new TreeNode(4);
    TreeNode *forth = new TreeNode(5);
    TreeNode *fifth = new TreeNode(2);
    TreeNode *sixth = new TreeNode(7);
    TreeNode *seventh = new TreeNode(6);
    first->left = second;
    first->right = third;
    second->left = forth;
    second->right = fifth;
    third->left = sixth;
    third->right = seventh;
    vector<int> ans = getInOrderTraversal(first);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
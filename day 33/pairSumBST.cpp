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
void inorder(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool pairSumBst(TreeNode<int> *root, int k)
{
    vector<int> ans;
    inorder(root, ans);
    int s = 0;
    int e = ans.size() - 1;
    while (s < e)
    {
        int sum = ans[s] + ans[e];
        if (sum == k)
            return true;
        if (sum > k)
            e--;
        else
            s++;
    }
    return false;
}
int main()
{
}

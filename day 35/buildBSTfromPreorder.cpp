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
// TreeNode<int>* solve(vector<int> &preOrder,int s,int e){
//     if(s>e) return NULL;
//     int mid=s+(e-s)/2;
//     TreeNode<int>* root=new TreeNode<int>(preOrder[mid]);
//     root->left=solve(preOrder,s,mid-1);
//     root->right=solve(preOrder,mid+1,e);
//     return root;
// }
TreeNode<int> *build(int &i, int mini, int maxi, vector<int> &arr)
{
    if (i >= arr.size())
    {
        return NULL;
    }
    TreeNode<int> *root = NULL;
    if (arr[i] > mini && arr[i] < maxi)
    {
        root = new TreeNode<int>(arr[i++]);
        root->left = build(i, mini, root->data, arr);
        root->right = build(i, root->data, maxi, arr);
    }
    return root;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // sort(preOrder.begin(),preOrder.end());
    // int start=0;
    // int end=preOrder.size()-1;
    // return solve(preOrder,start,end);
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;
    return build(index, mini, maxi, preOrder);
}
int main()
{
}
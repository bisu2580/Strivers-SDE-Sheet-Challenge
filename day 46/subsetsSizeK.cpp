#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int n, int k, vector<vector<int>> &ans, int sum, int index, vector<int> temp)
{
    if (index >= n)
    {
        if (sum == k)
        {
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(arr[index]);
    solve(arr, n, k, ans, sum + arr[index], index + 1, temp);
    temp.pop_back();
    solve(arr, n, k, ans, sum, index + 1, temp);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    solve(arr, n, k, ans, 0, index, temp);
    return ans;
}
int main()
{
    vector<int> ans = {2, 4, 6};
    auto num = findSubsetsThatSumToK(ans, ans.size(), 6);

    for (auto i : num)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int n, int target, int index, vector<int> &temp, vector<vector<int>> &ans)
{

    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
        return;
    for (int i = index; i < n; i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;
        temp.push_back(arr[i]);
        solve(arr, n, target - arr[i], i + 1, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(arr, n, target, 0, temp, ans);

    return ans;
}
int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans = combinationSum2(arr, arr.size(), 8);
    cout << endl
         << "The result is:" << endl;
    for (auto x : ans)
    {
        for (auto i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
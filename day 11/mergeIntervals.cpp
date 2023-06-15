#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 4}, {6, 8}, {10, 12}, {8, 9}};
    arr = mergeIntervals(arr);
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
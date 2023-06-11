#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        int rem = s - curr;
        if (mp[rem])
        {
            int count = mp[rem];
            vector<int> temp;
            while (count--)
            {
                temp.push_back(min(curr, rem));
                temp.push_back(max(curr, rem));
                ans.push_back(temp);
            }
        }
        mp[curr]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> nums = {3, 5, 1, 7, 3};
    vector<vector<int>> ans = pairSum(nums, 6);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
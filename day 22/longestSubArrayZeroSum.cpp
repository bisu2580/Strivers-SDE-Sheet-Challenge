#include <bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector<int> arr)
{
    int prev = 0;
    int maxi = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        prev += arr[i];
        if (prev == 0)
            maxi = i + 1;
        else if (mp.find(prev) != mp.end())
        {
            maxi = max(maxi, i - mp[prev]);
        }
        else
        {
            mp[prev] = i;
        }
    }
    return maxi;
}
int main()
{
    vector<int> v = {1, 3, -1, 4, -4};
    cout << "Length of longest subarray with zero sum is: " << LongestSubsetWithZeroSum(v);
}
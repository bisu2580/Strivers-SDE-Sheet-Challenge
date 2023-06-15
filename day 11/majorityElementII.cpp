#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    int length = arr.size();
    set<int> ans;
    map<int, int> mp;

    for (int i = 0; i < length; i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp[arr[i]] > (floor(length / 3)))
            ans.insert(arr[i]);
    }
    vector<int> res(ans.begin(), ans.end());

    return res;
}
int main()
{
    vector<int> nums = {3, 3, 3, 3, 2, 4, 4, 4, 4};
    nums = majorityElementII(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}
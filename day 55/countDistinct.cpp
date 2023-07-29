#include <bits/stdc++.h>
using namespace std;
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    unordered_map<int, int> m;
    vector<int> ans;
    int count = 0;
    // First Window
    for (int i = 0; i < k; i++)
    {
        if (m[arr[i]] == 0)
        {
            count++;
        }
        m[arr[i]]++;
    }
    ans.push_back(count);
    // Remaining window
    for (int i = k; i < arr.size(); i++)
    {
        if (m[arr[i - k]] == 1)
        {
            count--;
        }
        m[arr[i - k]]--;
        if (m[arr[i]] == 0)
        {
            count++;
        }
        m[arr[i]]++;
        ans.push_back(count);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    int k = 3;
    vector<int> ans = countDistinctElements(nums, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;
int findMajorityElement(int arr[], int n)
{
    int ans = -1;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second > floor(n / 2))
            ans = i.first;
    }
    return ans;
}
int main()
{
    int arr[] = {2, 1, 3, 4, 2, 2, 2, 2};
    cout << "Majority element is " << findMajorityElement(arr, 8);
}
#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int k)
{
    int xored = 0;
    map<int, int> mp;
    mp[xored]++;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xored ^= arr[i];
        int x = xored ^ k;
        count += mp[x];
        mp[xored]++;
    }
    return count;
}
int main()
{
    vector<int> arr = {5, 3, 8, 3, 10};
    int k = 8;
    cout << subarraysXor(arr, k);
}
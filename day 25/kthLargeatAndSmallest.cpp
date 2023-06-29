#include <bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
}
int main()
{
    vector<int> arr = {3, 6, 1, 5, 7};
    int n = 5;
    int k = 2;
    vector<int> ans = kthSmallLarge(arr, n, k);
    cout << ans[0] << " " << ans[1];
}
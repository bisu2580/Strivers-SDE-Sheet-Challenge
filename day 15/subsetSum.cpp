#include <bits/stdc++.h>
using namespace std;
void rec(vector<int> &arr, int index, vector<int> &ans, int sum)
{
    if (index >= arr.size())
    {
        ans.push_back(sum);
        return;
    }
    // pick
    sum += arr[index];
    rec(arr, index + 1, ans, sum);
    // Not pick
    sum -= arr[index];
    rec(arr, index + 1, ans, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int sum = 0;
    rec(num, 0, ans, sum);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    nums = subsetSum(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}
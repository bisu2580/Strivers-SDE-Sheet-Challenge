#include <bits/stdc++.h>
using namespace std;
int findMinimumCoins(int amount)
{
    vector<int> nums = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0;
    int index = 0;
    while (amount)
    {
        if (amount >= nums[index])
        {
            amount -= nums[index];
            ans++;
        }
        else
            index++;
    }
    return ans;
}
int main()
{
    cout << findMinimumCoins(290);
}
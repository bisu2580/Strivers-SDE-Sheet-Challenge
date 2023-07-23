#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    long *dp = new long[value + 1]();
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = denominations[i]; j <= value; j++)
        {
            dp[j] += dp[j - denominations[i]];
        }
    }
    return dp[value];
}
int main()
{
    int *arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    cout << countWaysToMakeChange(arr, 3, 4);
}
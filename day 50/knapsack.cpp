#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int w, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[0] <= w)
            return value[0];
        return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notTake = 0 + solve(ind - 1, w, weight, value, dp);
    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = value[ind] + solve(ind - 1, w - weight[ind], weight, value, dp);
    }
    return dp[ind][w] = max(take, notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, weights, values, dp);
}
int main()
{
    vector<int> w = {1, 2, 4, 5};
    vector<int> v = {5, 4, 8, 6};
    cout << maxProfit(v, w, 4, 5) << endl;
}
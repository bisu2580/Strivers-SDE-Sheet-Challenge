#include <bits/stdc++.h>
using namespace std;
int solveTab(string &a, string &b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i][j + 1], dp[i + 1][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int lcs(string s, string t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return solveTab(s, t);
}
int main()
{
    string a = "adebc";
    string b = "dcadb";
    cout << lcs(a, b);
}
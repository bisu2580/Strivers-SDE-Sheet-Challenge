#include <bits/stdc++.h>
using namespace std;
int help(int i, string s, set<string> word, vector<int> &dp)
{
    if (i == s.size())
        return 1;
    string temp;
    if (dp[i] != -1)
        return dp[i];
    for (int j = i; j < s.size(); j++)
    {
        temp += s[j];
        if (word.find(temp) != word.end())
        {
            if (help(j + 1, s, word, dp))
                return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}
bool wordBreak(vector<string> &arr, int n, string &target)
{
    vector<int> dp(100, -1);
    set<string> s;
    for (auto a : arr)
    {
        s.insert(a);
    }
    return help(0, target, s, dp);
}
int main()
{
    vector<string> ans = {"coding", "ninjas", "is", "awesome"};
    string target = "codingninjas";
    cout << wordBreak(ans, ans.size(), target);
}
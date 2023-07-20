#include <bits/stdc++.h>
using namespace std;
bool isPal(string st, int s, int e)
{
    while (s <= e)
    {
        if (st[s++] != st[e--])
            return false;
    }
    return true;
}
void solve(int i, string &s, vector<string> &temp, vector<vector<string>> &ans)
{
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int k = i; k < s.size(); k++)
    {
        if (isPal(s, i, k))
        {
            temp.push_back(s.substr(i, k - i + 1));
            solve(k + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    vector<string> temp;
    vector<vector<string>> ans;
    solve(0, s, temp, ans);
    return ans;
}
int main()
{
    string s = "aabb";
    auto res = partition(s);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
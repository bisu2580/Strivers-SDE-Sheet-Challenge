#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_func(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
bool findPattern(string p, string s)
{
    vector<int> res = prefix_func(p);
    int pos = -1;
    int i = 0, j = 0;
    while (i < s.size())
    {
        if (s[i] == p[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j != 0)
                j = res[j - 1];
            else
                i++;
        }
        if (j == p.size())
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s = "ababacb";
    string p = "bac";
    cout << findPattern(p, s) << endl; // Output: True
}
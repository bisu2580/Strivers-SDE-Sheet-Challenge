#include <bits/stdc++.h>
using namespace std;
int uniqueSubstrings(string input)
{
    vector<int> mp(256, -1);
    int start = 0, end = 0;
    int n = input.size();
    int len = 0;
    while (end < n)
    {
        if (mp[input[end]] != -1)
        {
            start = max(mp[input[end]] + 1, start);
        }
        mp[input[end]] = end;
        len = max(len, end - start + 1);
        end++;
    }
    return len;
}
int main()
{
    string num = "aadfabdcghij";
    cout << uniqueSubstrings(num) << endl;
}
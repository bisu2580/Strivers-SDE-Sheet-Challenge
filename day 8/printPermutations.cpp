#include <bits/stdc++.h>
using namespace std;
void findPermutation(string s, vector<string> &ans, vector<int> &visited, string &num)
{
    if (num.size() == s.size())
    {
        ans.push_back(num);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (!visited[i])
        {
            num += s[i];
            visited[i] = 1;
            findPermutation(s, ans, visited, num);
            visited[i] = 0;
            num.pop_back();
        }
    }
}
vector<string> findPermutations(string &s)
{
    vector<string> ans;
    vector<int> temp(s.size(), 0);
    string num = "";
    for (int i = 0; i < s.size(); i++)
    {
        temp[i] = 0;
    }
    findPermutation(s, ans, temp, num);
    return ans;
}
int main()
{
    string s = "abc";
    vector<string> ans = findPermutations(s);
    for (auto ch : ans)
    {
        cout << ch << endl;
    }
}
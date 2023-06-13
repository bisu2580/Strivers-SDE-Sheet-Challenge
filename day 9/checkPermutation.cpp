#include <bits/stdc++.h>
using namespace std;
bool areAnagram(string &str1, string &str2)
{
    vector<int> count(26, 0);
    for (int i = 0; i < str1.size(); i++)
    {
        count[str1[i] - 'a']++;
    }
    for (int i = 0; i < str2.size(); i++)
    {
        count[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string s1 = "listen";
    string s2 = "silent";
    if (areAnagram(s1, s2))
    {
        cout << "These are anagrams of each other";
    }
    else
    {
        cout << "These are not anagrams of each other";
    }
}
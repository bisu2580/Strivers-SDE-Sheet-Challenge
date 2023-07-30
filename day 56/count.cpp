#include <bits/stdc++.h>
using namespace std;
string writeAsYouSpeak(int n)
{
    string ans = "1";
    if (n == 1)
        return ans;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        string temp;
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j] == ans[j + 1])
                count++;
            else
            {
                temp += to_string(count);
                temp += ans[j];
                count = 1;
            }
        }
        ans = temp;
    }
    return ans;
}
int main()
{
}
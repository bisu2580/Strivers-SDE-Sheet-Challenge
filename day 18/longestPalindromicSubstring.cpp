#include <bits/stdc++.h>
using namespace std;
string longestPalinSubstring(string str)
{
    int left, right;
    int start = 0, end = 1;
    int n = str.length();
    for (int i = 1; i < n; i++)
    {
        // Checking for even
        left = i - 1;
        right = i;

        while (left >= 0 && right < n && str[left] == str[right])
        {
            int count = right - left + 1;
            if (count > end)
            {
                start = left;
                end = count;
            }
            left--;
            right++;
        }
        // Checking for odd
        left = i - 1;
        right = i + 1;

        while (left >= 0 && right < n && str[left] == str[right])
        {
            int count = right - left + 1;
            if (count > end)
            {
                start = left;
                end = count;
            }
            left--;
            right++;
        }
    }
    string ans = str.substr(start, end);
    return ans;
}
int main()
{
    string a = "bccb";
    cout << longestPalinSubstring(a).data();
}
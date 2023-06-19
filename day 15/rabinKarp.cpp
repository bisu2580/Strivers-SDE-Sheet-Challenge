#include <bits/stdc++.h>
using namespace std;
vector<int> stringMatch(string text, string pattern)
{
    vector<int> ans;
    int d = 256;
    int M = pattern.size();
    int N = text.size();
    int i, j;
    int q = 101;

    int pattern_hash = 0;
    int text_hash = 0;
    int hash = 1;

    for (i = 0; i < M - 1; i++)
    {
        hash = (hash * d) % q;
    }

    // Calculate for first window
    for (i = 0; i < M; i++)
    {
        pattern_hash = (d * pattern_hash + pattern[i]) % q;
        text_hash = (d * text_hash + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (pattern_hash == text_hash)
        {
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
            {
                ans.push_back(i + 1);
            }
        }

        if (i < N - M)
        {
            text_hash = (d * (text_hash - text[i] * hash) + text[i + M]) % q;
            if (text_hash < 0)
                text_hash += q;
        }
    }
    return ans;
}
int main()
{
    string text = "GEEKSFORGEEKS";
    string pattern = "GEEK";

    vector<int> ans = stringMatch(text, pattern);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
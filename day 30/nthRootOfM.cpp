#include <bits/stdc++.h>
using namespace std;
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m)
{
    int start = 1;
    int end = m;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int midN = func(mid, n, m);
        if (midN == 2)
        {
            end = mid - 1;
        }
        else if (midN == 1)
        {
            return mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    cout << NthRoot(3, 27);
}
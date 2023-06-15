#include <bits/stdc++.h>
using namespace std;
int modularExponentiation(int x, int n, int m)
{
    long ans = 1;
    long num = n;
    long xx = x;
    while (num > 0)
    {
        if (num & 1)
        {
            ans = ((ans) % m * (xx % m) % m) % m;
        }
        xx = ((xx) % m * (xx) % m) % m;
        num = num >> 1;
    }
    return (int)ans % m;
}
int main()
{
    cout << modularExponentiation(3, 4, 4);
}
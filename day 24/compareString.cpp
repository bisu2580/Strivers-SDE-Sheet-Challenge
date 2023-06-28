#include <bits/stdc++.h>
using namespace std;
int compareVersions(string a, string b)
{
    int i = 0, j = 0;
    int size1 = a.size();
    int size2 = b.size();
    long long n1, n2;
    while (i < size1 || j < size2)
    {
        n1 = 0;
        n2 = 0;
        while (i < size1 && a[i] != '.')
        {
            n1 = n1 * 10 + (a[i] - '0');
            i++;
        }
        while (j < size2 && b[j] != '.')
        {
            n2 = n2 * 10 + (b[j] - '0');
            j++;
        }
        if (n1 < n2)
            return -1;
        else if (n1 > n2)
            return 1;
        i++;
        j++;
    }
    return 0;
}
int main()
{
    string a = "127.23.8";
    string b = "127.345.9";
    cout << compareVersions(a, b);
}
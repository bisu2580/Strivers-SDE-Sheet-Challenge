#include <bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int platform = 1;
    int maxi = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            platform++;
            i++;
        }
        else if (at[i] > dt[j])
        {
            platform--;
            j++;
        }
        maxi = max(maxi, platform);
    }
    return maxi;
}
int main()
{
    int at[] = {900, 940, 950, 1100, 1500, 1800};
    int dt[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(at) / sizeof(at[0]);
    cout << calculateMinPatforms(at, dt, n);
}
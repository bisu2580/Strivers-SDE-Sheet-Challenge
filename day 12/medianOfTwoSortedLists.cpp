#include <bits/stdc++.h>
using namespace std;
double median(vector<int> &a, vector<int> &b)
{
    if (b.size() < a.size())
        return median(b, a);
    int n1 = a.size();
    int n2 = b.size();

    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1, left2, right1, right2;

        if (cut1 == 0)
            left1 = INT_MIN;
        else
            left1 = a[cut1 - 1];
        if (cut2 == 0)
            left2 = INT_MIN;
        else
            left2 = b[cut2 - 1];

        if (cut1 == n1)
            right1 = INT_MAX;
        else
            right1 = a[cut1];
        if (cut2 == n2)
            right2 = INT_MAX;
        else
            right2 = b[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) & 1)
            {
                return max(left1, left2);
            }
            else
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}
int main()
{
    vector<int> a = {2, 4, 6};
    vector<int> b = {1, 3};
    cout << median(a, b);
}
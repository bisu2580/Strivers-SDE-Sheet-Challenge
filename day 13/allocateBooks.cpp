#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int days, int chapters, long long mid)
{
    long long dayCount = 1;
    long long chapterSum = 0;
    for (int i = 0; i < chapters; i++)
    {
        if (chapterSum + arr[i] <= mid)
        {
            chapterSum += arr[i];
        }
        else
        {
            dayCount++;
            if (dayCount > days || arr[i] > mid)
            {
                return false;
            }
            chapterSum = arr[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int days, int chapters, vector<int> time)
{
    // search space is the total sum of array.
    long long s = 0;
    long long sum = 0;
    for (int i = 0; i < chapters; i++)
    {
        sum += time[i];
    }
    long long e = sum;
    long long ans = -1;

    long long mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(time, days, chapters, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> time = {1, 2, 2, 3, 1};
    cout << "Minimum time: " << ayushGivesNinjatest(3, 5, time);
}
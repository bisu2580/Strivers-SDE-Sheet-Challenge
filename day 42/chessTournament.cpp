#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> positions, int &count, int &prev, int n, int mid, int c)
{
    for (int i = 1; i < n; i++)
    {
        if (positions[i] - prev >= mid)
        {
            count++;
            prev = positions[i];
        }
    }
    return count >= c;
}
int chessTournament(vector<int> positions, int n, int c)
{
    sort(positions.begin(), positions.end());
    int s = 1;
    int maxi = 0;
    int e = positions[n - 1];
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int count = 1;
        int prev = positions[0];
        if (isPossible(positions, count, prev, n, mid, c))
        {
            maxi = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 6};
    cout << chessTournament(nums, nums.size(), 3);
}
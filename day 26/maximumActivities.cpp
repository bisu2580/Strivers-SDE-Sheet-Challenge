#include <bits/stdc++.h>
using namespace std;
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < start.size(); i++)
    {
        v.emplace_back(make_pair(finish[i], start[i]));
    }
    sort(v.begin(), v.end());
    int e = -1;
    int ans = 0;
    for (auto val : v)
    {
        if (val.second > e - 1)
        {
            ans++;
            e = val.first;
        }
    }
    return ans;
}
int main()
{
    vector<int> start = {1, 6, 2, 4};
    vector<int> end = {2, 7, 5, 8};
    cout << maximumActivities(start, end);
}
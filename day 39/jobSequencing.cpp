#include <bits/stdc++.h>
using namespace std;
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int n = jobs.size();
    int maxDeadLine = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDeadLine = max(maxDeadLine, jobs[i][0]);
    }
    vector<int> ans(maxDeadLine + 1, -1);
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int currDead = jobs[i][0];
        int currProfit = jobs[i][1];
        for (int k = currDead; k > 0; k--)
        {
            if (ans[k] == -1)
            {
                profit += currProfit;
                ans[k] = 1;
                break;
            }
        }
    }
    return profit;
}
int main()
{
    vector<vector<int>> nums = {{2, 30}, {2, 40}, {1, 10}, {1, 10}};
    cout << jobScheduling(nums);
}
#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
    int minimumTillIndex = prices[0];
    int j = 1;
    int profit = 0;
    while (j <= prices.size() - 1)
    {
        int diff = prices[j] - minimumTillIndex;
        profit = max(profit, diff);
        minimumTillIndex = min(minimumTillIndex, prices[j]);
        j++;
    }
    return profit;
}
int main()
{
    vector<int> arr = {17, 20, 11, 9, 12, 6};
    cout << "Maximum profit is " << maximumProfit(arr);
}
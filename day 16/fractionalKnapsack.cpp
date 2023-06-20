#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return ((double)a.second / a.first) > ((double)b.second / b.first);
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Sorting in decreasing order(get max weight/value)
    sort(items.begin(), items.end(), compare);
    int currentWeight = 0;
    double maxvalue = 0;

    for (int i = 0; i < n; i++)
    {
        int weight = items[i].first;
        int value = items[i].second;

        if (currentWeight + weight <= w)
        {
            currentWeight += weight;
            maxvalue += value;
        }
        else
        {
            int remWeight = w - currentWeight;
            maxvalue += value * ((double)remWeight / weight);
            break;
        }
    }
    return maxvalue;
}
int main()
{
    vector<pair<int, int>> ans = {{6, 3}, {1, 6}, {5, 1}, {3, 4}};
    cout << "Max Value: " << maximumValue(ans, 4, 10);
}
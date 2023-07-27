#include <bits/stdc++.h>
using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<pair<int, pair<int, int>>> mxHeap;
    mxHeap.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});

    set<pair<int, int>> mySet;
    mySet.insert({n - 1, n - 1});

    vector<int> result;

    while (k > 0)
    {
        pair<int, pair<int, int>> node = mxHeap.top();
        mxHeap.pop();

        int sum = node.first;
        int x = node.second.first;
        int y = node.second.second;

        result.push_back(sum);

        if (mySet.find({x - 1, y}) == mySet.end())
        {
            mxHeap.push({a[x - 1] + b[y], {x - 1, y}});
            mySet.insert({x - 1, y});
        }
        if (mySet.find({x, y - 1}) == mySet.end())
        {
            mxHeap.push({a[x] + b[y - 1], {x, y - 1}});
            mySet.insert({x, y - 1});
        }
        k--;
    }
    return result;
}
int main()
{
    vector<int> a = {1, 3, 5};
    vector<int> b = {6, 4, 2};
    int k = 2;
    cout << "Maximum Sum Combination is: ";
    vector<int> ans = kMaxSumCombination(a, b, 3, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

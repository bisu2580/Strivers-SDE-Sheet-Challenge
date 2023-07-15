#include <bits/stdc++.h>
using namespace std;
class data
{
public:
    int val, apos, bpos;
    data(int v, int ap, int bp)
    {
        val = v;
        apos = ap;
        bpos = bp;
    }
};
struct comp
{
    bool operator()(data &d1, data &d2)
    {
        return d1.val > d2.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<data, vector<data>, comp> pq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        data d(arr[i][0], i, 0);
        pq.push(d);
    }
    while (!pq.empty())
    {
        data curr = pq.top();
        pq.pop();
        ans.push_back(curr.val);
        int ap = curr.apos;
        int vp = curr.bpos;
        if (vp + 1 < arr[ap].size())
        {
            data d(arr[ap][vp + 1], ap, vp + 1);
            pq.push(d);
        }
    }
    return ans;
}
int main()
{
}
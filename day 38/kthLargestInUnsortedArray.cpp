#include <bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> &arr, int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < K; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = K; i < N; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main()
{
    vector<int> nums = {2, 1, 5, 6, 3, 8};
    cout << "K'th largest element is: " << kthLargest(nums, nums.size(), 3);
}
#include <bits/stdc++.h>
using namespace std;
string fourSum(vector<int> arr, int target, int n)
{
    string ans = "No";
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target)
                {
                    ans = "Yes";
                    k++;
                    l--;
                    if (k < l && arr[k] == arr[k - 1])
                        k++;
                    else if (k < l && arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 3, 3, 10, 2};
    int target = 9;
    cout << fourSum(arr, target, arr.size());
}
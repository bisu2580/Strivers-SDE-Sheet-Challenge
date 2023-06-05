#include <bits/stdc++.h>
using namespace std;
vector<long long> rowGenerator(long long row)
{
    vector<long long> ans;
    ans.push_back(1);
    long long i = 1;
    for (int col = 1; col < row; col++)
    {
        i *= (row - col);
        i /= col;
        ans.push_back(i);
    }
    return ans;
}
vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long>> answer;
    for (int i = 1; i <= n; i++)
    {
        vector<long long> newRow = rowGenerator(i);
        answer.push_back(newRow);
    }
    return answer;
}
int main()
{
    vector<vector<long long int>> res = printPascal(4);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
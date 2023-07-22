#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, vector<int> color, vector<vector<int>> mat, int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && mat[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, vector<int> &color, int m, int n, vector<vector<int>> &mat)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, mat, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, mat))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int vertices = mat.size();
    vector<int> color(vertices, 0);
    if (solve(0, color, m, vertices, mat))
        return "YES";
    return "NO";
}
int main()
{
    vector<vector<int>> mat = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    cout << graphColoring(mat, 2).data() << endl;
}
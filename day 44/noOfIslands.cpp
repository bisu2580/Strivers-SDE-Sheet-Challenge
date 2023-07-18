#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<bool>> &visited, int x, int y, vector<vector<int>> &arr, int n, int m)
{
    if (arr[x][y] == 0)
        return;
    visited[x][y] = true;
    int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
    for (int i = 0; i < 8; i++)
    {
        int nr = x + dx[i];
        int nc = y + dy[i];
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && (!visited[nr][nc]) && (arr[nr][nc] == 1))
        {
            dfs(visited, nr, nc, arr, n, m);
        }
    }
}
int getTotalIslands(vector<vector<int>> &arr, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                dfs(visited, i, j, arr, n, m);
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> ans = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
    cout << getTotalIslands(ans, 4, 4) << endl; // Output:
}
#include <bits/stdc++.h>
using namespace std;
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<int>> arr = grid;
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                fresh++;
            else if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int steps = 0;
    while (!q.empty() && fresh > 0)
    {
        int currSize = q.size();
        while (currSize--)
        {
            auto orange = q.front();
            q.pop();
            int x = orange.first;
            int y = orange.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                    fresh--;
                }
            }
        }
        steps++;
    }
    if (fresh > 0)
        return -1;
    return steps;
}
int main()
{
    vector<vector<int>> ans = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << minTimeToRot(ans, 3, 3);
}
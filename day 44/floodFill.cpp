#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, map<pair<int, int>, bool> &visited, int row, int col, int newCol, int oldCol)
{
    visited[{row, col}] = true;
    image[row][col] = newCol;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newr = row + dx[i];
        int newc = col + dy[i];
        if (newr >= 0 && newr < image.size() && newc >= 0 && newc < image[0].size() && !visited[{newr, newc}] &&
            image[newr][newc] == oldCol)
        {
            dfs(image, visited, newr, newc, newCol, oldCol);
        }
    }
}
void bfs(vector<vector<int>> &image, map<pair<int, int>, bool> &visited, int row, int col, int newCol, int oldCol)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[{row, col}] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto fNode = q.front();
        q.pop();
        int x = fNode.first;
        int y = fNode.second;
        image[x][y] = newCol;
        for (int i = 0; i < 4; i++)
        {
            int newr = x + dx[i];
            int newc = y + dy[i];
            if (newr >= 0 && newr < image.size() && newc >= 0 && newc < image[0].size() && !visited[{newr, newc}] &&
                image[newr][newc] == oldCol)
            {
                q.push({newr, newc});
                visited[{newr, newc}] = true;
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    vector<vector<int>> nums = image;
    map<pair<int, int>, bool> visited;
    int oldCol = nums[x][y];
    bfs(nums, visited, x, y, newColor, oldCol);
    return nums;
}
int main()
{
    vector<vector<int>> v = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    v = floodFill(v, 1, 1, 2);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
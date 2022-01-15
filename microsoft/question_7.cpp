#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grid, int i, int j)
{

    int r = grid.size(), c = grid[0].size();

    queue<pair<int, int>> q;

    // insert current node
    q.push({i, j});
    grid[i][j] = 2;
    int size = 1;

    vector<pair<int, int>> neighbour = {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1}};

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (auto &p : neighbour)
        {
            int x = curr.first + p.first,
                y = curr.second + p.second;
            if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 1)
            {
                grid[x][y] = 2;
                q.push({x, y});
                size++;
            }
        }
    }

    return size;
}

int findMaxArea(vector<vector<int>> &grid)
{
    int max_area = 0;

    int r = grid.size(), c = grid[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                max_area = max(max_area, bfs(grid, i, j));
            }
        }
    }

    return max_area;
}
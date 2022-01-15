#include <bits/stdc++.h>
using namespace std;

// return true : if cycle detected
bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &tmp, int i)
{
    visited[i] = true;
    tmp[i] = true;

    for (int n : adjList[i])
    {
        if (!visited[n])
        {
            if (dfs(adjList, visited, tmp, n))
                return true;
        }
        else if (tmp[n])
        {
            return true;
        }
    }

    tmp[i] = false;
    return false;
}

bool isPossible(int N, vector<pair<int, int>> &prereq)
{
    vector<vector<int>> adjList(N);

    for (auto &v : prereq)
    {
        adjList[v.first].push_back(v.second);
    }

    vector<bool> visited(N, 0), tmp(N, 0);

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && dfs(adjList, visited, tmp, i))
        {
            return false;
        }
    }

    return true;
}
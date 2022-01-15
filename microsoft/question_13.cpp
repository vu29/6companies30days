#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *adj, int V, vector<bool> &visited, int &count, int i){

    visited[i] = true;
    count++;

    for (int n : adj[i])
    {
        if (!visited[n])
        {
            dfs(adj, V, visited, count, n);
        }
    }
}

public:
// Function to find if the given edge is a bridge in graph.
int isBridge(int V, vector<int> adj[], int c, int d){

    int count = 0;
    auto &v1 = adj[c], &v2 = adj[d];

    v1.erase(remove(v1.begin(), v1.end(), d), v1.end());
    v2.erase(remove(v2.begin(), v2.end(), c), v2.end());

    vector<bool> visited(V, 0);

    dfs(adj, V, visited, count, 0);

    return count != V;
}
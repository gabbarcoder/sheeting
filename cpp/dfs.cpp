#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;

    ls.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

void dfsofgraph(int V, vector<int> adj[])
{
    int vis[n] = {0};
    int start = {0};
    vector<int> ls;

    dfs(start, adj[], vis, ls);
}

int main()
{   
    
    return 0;
}
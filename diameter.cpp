#include <bits/stdc++.h>
using namespace std;

vector<int> height(100, 0);
vector<int> depth(100, 0);

void dfs(int s, int p, vector<int> adj[])
{
    cout << s;

    for (int child : adj[s])
    {

        if (child == p)
            continue;
        depth[child] = depth[s] + 1;
        dfs(child, s, adj);
        height[s] = max(height[s], (height[child] + 1));
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < v; i++)
    {
        cout << "vertice" << i << "->";

        for (auto x : adj[i])
        {
            cout << x << "->";
        }
        cout << "NULL";
    }

    dfs(0, -1, adj);

    int max_depth = -1;
    int max_d_node;

    for (int i = 0;i<v;i++)
    {
        if(max_depth<depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(max_d_node, -1, adj);
    max_depth = -1;

    for (int i = 0; i < v; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
    }
    cout << max_depth << endl;

    return 0;
}
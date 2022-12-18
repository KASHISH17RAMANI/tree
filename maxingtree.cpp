#include <bits/stdc++.h>
using namespace std;

int maximum = -1;


void dfs(int s, int p, vector<int> adj[])
{
    
    if(maximum<s)
    {
         maximum = s;
    }

    for (int child : adj[s])
    {

        if (child == p)
            continue;
    
        dfs(child, s, adj);
        

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

    

    dfs(0, -1, adj);

    cout << maximum;

    return 0;
}

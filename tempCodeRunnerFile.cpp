#include <bits/stdc++.h>
using namespace std;



void dfs(int s, int p, vector<int> adj[])
{

    cout << "node pre" << s << endl;
    for (int child : adj[s])
    {

        if (child == p)
            continue;
        cout << "edge pre" << s << "----" << child<<endl;
        
        dfs(child, s, adj);
        cout << "edge post" << s << "----" << child<<endl;
        
    }
    cout << "node post" << s << endl;
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
    cout << "node pre" << 0 << endl;
    dfs(0, -1, adj);

    

    return 0;
}

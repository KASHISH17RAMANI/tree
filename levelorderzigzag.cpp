#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100, 0);
void levelorder(int s, vector<int> adj[])
{
    queue<int> q;

    q.push(s);
    while (!q.empty())
    {
        int t;
        t = q.front();
        q.pop();
        visited[t] = 1;
        cout << t;
        for (int child : adj[t])
        {
            if (visited[child] == 0)
                q.push(child);
        }
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

    levelorder(0, adj);

    return 0;
}

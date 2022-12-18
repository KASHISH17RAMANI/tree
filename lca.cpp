#include<bits/stdc++.h>
using namespace std;

int parent[100];

void dfs(int s,int p,vector<int>adj[])
{
    parent[s] = p;
    for(int child:adj[s])
    {
        if(child==p)
            continue;
        dfs(child, s, adj);
    }
}

vector<int>path(int v){
    vector<int> ans;
    while(v!=-1)
    {
        ans.push_back(v);
        v = parent[v];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


void lca(int a,int b)
{
    for (int i = 0; i < path(a).size();i++)
    {
        if(path(a)[i]==path(b)[i])
            continue;
        else{
            cout << path(a)[--i];
            break;
        }      
       
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int>adj[v];
    for (int i = 0; i < e;i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, adj);
    lca(11, 10);
}

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<bool>&vis,vector<int>&tim,vector<int>&low,int &timer,vector<int>adj[])
{
    vis[node]=1;
    tim[node]=low[node]=timer++;
    for(auto it:adj[node])
    {
        if(it==par)
            continue;
        if(!vis[it])
        {
            dfs(it,node,vis,tim,low,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>tim[node])
            {
                cout<<node<<"-"<<it<<endl;
            }
            else
            {
                low[node]=min(low[node],tim[it]);
            }
        }
    }
}



int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n,0);
    vector<int>tim(n,-1);
    vector<int>low(n,-1);
    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,tim,low,timer,adj);
        }
    }
    return 0;
}

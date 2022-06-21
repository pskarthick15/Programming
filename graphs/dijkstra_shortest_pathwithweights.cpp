// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int N,int src,vector<pair<int,int>>adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<int>dis(N+1,INT_MAX);
    dis[src]=0;
    q.push({dis[src],src});
    while(!q.empty())
    {
        int node=q.top().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(dis[node]+it.second<dis[it.first])
            {
                dis[it.first]=dis[node]+it.second;
                q.push(it);
            }
        }
    }
    return dis;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m,u,v,wt;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];//Now our graph has weights for edges
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int src;
    cin>>src;
    vector<int>ans=dijkstra(n,src,adj);
    for(int i=1;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

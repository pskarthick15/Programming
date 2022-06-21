// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


vector<int> shortestdis(int N,int src,vector<int>adj[])
{
    vector<int>dis(N,INT_MAX);
    queue<int>q;
    dis[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dis[node]+1 < dis[it])
            {
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
    return dis;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    vector<int>ans=shortestdis(n,src,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

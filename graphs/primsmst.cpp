// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;




void primsmst(int N,int src,vector<pair<int,int>>adj[])
{
    vector<int>key(N,INT_MAX);
    vector<int>mstinclude(N,false);
    vector<int>parent(N,-1);
    key[src]=0;
    mstinclude[src]=true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int count=0;count<N-1;count++)
    {
        int u=q.top().second;
        q.pop();
        mstinclude[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mstinclude[v]==false && weight<key[v])
            {
                parent[v]=u;
                q.push({key[v],v});
                key[v]=weight;
            }
        }
    }
    for(int i=1;i<N;i++)
    {
        cout<<parent[i]<<"-"<<i<<"\n";
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int u,v,wt;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int src;
    cin>>src;
    primsmst(n,src,adj);
    return 0;
}

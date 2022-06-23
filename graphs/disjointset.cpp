// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


void makeset(vector<int>&parent,vector<int>&rank)
{
    for(int i=0;i<parent.size();i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int findparent(int node,vector<int>&par)
{
    if(node==par[node])
    {
        return node;
    }
    return par[node]=findparent(par[node],par);
}


void Union(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findparent(u,parent);
    v=findparent(v,parent);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else //Cand  attach any rank to any but if ranks are equal our new rank after adding them will increase
    {
        parent[v]=u;
        rank[u]++;
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cout<<"Enter no of nodes\n";
    cin>>n;
    // vector<int>adj[n];
    // int u,v;
    // cout<<"Enter the edges\n";
    // for(int i=0;i<m;i++)
    // {
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    vector<int>parent(n);
    vector<int>rank(n);
    makeset(parent,rank);
    int a,b;
    int k;
    cout<<"Enter no of union queries\n";
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        Union(a,b,parent,rank);
        cout<<findparent(a,parent)<<" "<<findparent(b,parent)<<endl;
    }
    
    return 0;
}

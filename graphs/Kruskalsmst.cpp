// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int u1,int v1,int wt1)
    {
        u=u1;
        v=v1;
        wt=wt1;
    }
    
};

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


bool comp(node a,node b)
{
    if(a.wt<=b.wt)
        return true;
    else
        return false;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cout<<"Enter no of nodes and edges\n";
    cin>>n>>m;
    int u,v,wt;
    cout<<"Enter the connections with weights\n";
    vector<node>N;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>wt;
        N.push_back(node(u,v,wt));
    }
    sort(N.begin(),N.end(),comp); //Sort the linear ds according to weights
    vector<int>parent(n+1);
    vector<int>rank(n+1);
    makeset(parent,rank);
    vector<pair<int,int>>mst;
    int cost=0;
    for(int i=0;i<m;i++)
    {
        if(findparent(N[i].u,parent)!=findparent(N[i].v,parent)) // If both belong to different components
        {
            cost+=N[i].wt;
            mst.push_back({N[i].u,N[i].v});
            Union(N[i].u,N[i].v,parent,rank);
        }
    }
    cout<<"The cost of building MST is: "<<cost<<endl;
    for(auto it:mst)
    {
        cout<<it.first<<"-"<<it.second<<endl;
    }
    return 0;
}

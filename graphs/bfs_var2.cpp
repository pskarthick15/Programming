// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void bfs(int node,vector<int>adj[],vector<bool>&vis)
{
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
}


int bfscomponents(int n,vector<int>adj[])
{
    int cnt=0;
    vector<bool>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
           cnt++;
           bfs(i,adj,vis);
        }
    }
    return cnt;
}


int bfsextraedges(int node,vector<int>adj[],vector<bool>&vis)
{
    int cnt=0;
    vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(!q.empty())
    {
        int n=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,n});
            }
            else
            {
                if(par!=-1 && it!=par)
                {
                    cnt++;//Count the no of not needed edges
                    break;
                }
            }
        }
    }
    return cnt;
}

int bfscompedges(int n,vector<int>adj[])
{
    //For finding the no of waste edges for each component
    int k=0;
    int l;
    vector<bool>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
           l=bfsextraedges(i,adj,vis);
            k+=l;
        }
    }
    return k;
}




int makeConnected(int n,vector<vector<int>>& connections)
{
    vector<int>adj[n];
    int m=connections.size();
    //Forming the adjacency list
    for(int i=0;i<m;i++)
    {
       adj[connections[i][0]].push_back(connections[i][1]);
       adj[connections[i][1]].push_back(connections[i][0]);
    }
    int no_of_components=bfscomponents(n,adj);
    int no_of_extra_edges=bfscompedges(n,adj);
    if(no_of_extra_edges>=no_of_components)
        return no_of_extra_edges-1;
    else
        return -1;
}



int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<vector<int>>connections;
    vector<int>k;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        k.push_back(u);
        k.push_back(v);
        connections.push_back(k);
        k.clear();
    }
    cout<<makeConnected(n,connections);
    return 0;
}

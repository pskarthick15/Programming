// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void bfstraversal(int node,vector<int>graph[],vector<bool>&vis,vector<int>&bfs)
{
    queue<int>q;
    q.push(node);
    while(!q.empty())
    {
        int n=q.front();
        vis[n]=1;
        q.pop();
        bfs.push_back(n);
        for(auto it:graph[n])
        {
            if(!vis[it])
            {
                q.push(it);
            }
        }
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m,u,v;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //BFS traversal
    vector<bool>visited1(n+1,0);
    vector<int>bfs;
    vector<int>dfs;
    for(int i=1;i<=n;i++)//Doing traversal for all componenets
    {
        if(!visited1[i])
            bfstraversal(i,g,visited1,bfs);
    }
    for(int i=0;bfs.size();i++)
    {
        cout<<bfs[i]<<" ";
    }
    cout<<endl;
    /*for(int i=1;i<=n;i++)//Doing traversal for all componenets
    {
        if(!visited2[i])
            dfstraversal(i,g,visited,dfs);
    }*/
    return 0;
}

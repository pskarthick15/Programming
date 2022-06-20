// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isCycle(int i,vector<int>graph[],vector<bool>&vis)
{
    queue<pair<int,int>>q;
    q.push({i,-1});
    vis[i]=1;
    while(!q.empty())
    {
        int n=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:graph[n])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,n});
            }
            else
            {
                if(it!=par)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool cycleallcomp(vector<int>g[],vector<bool>vis,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(isCycle(i,g,vis))
                return true;
        }
    }
    return false;
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
    vector<bool>visited(n+1,0);
    //The approach is that in case if a node is visited and its parent is not = to the one taken from adjacency list, then it means the node was visited by some other nodes traversal already.
    cout<<cycleallcomp(g,visited,n);
    
}

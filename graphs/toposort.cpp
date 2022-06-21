// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


void toposortdfs(int node,vector<int>adj[],vector<bool>&vis,stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            toposortdfs(it,adj,vis,st);
    }
    st.push(node);
}

void toposortbfs(vector<int>adj[],vector<int>&indegree,vector<int>&ans)
{
    queue<int>q;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
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
    vector<int>adj[n];
    vector<int>indegree(n,0);
    //Topological sort for directed graph
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<bool>vis(n,0);
    stack<int>st;
    vector<int>ansdfs;
    vector<int>ansbfs;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            toposortdfs(i,adj,vis,st);
        }
    }
    while(!st.empty())
    {
        ansdfs.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<ansdfs.size();i++)
    {
        cout<<ansdfs[i]<<" ";
    }
    cout<<endl;
    toposortbfs(adj,indegree,ansbfs);
    for(int i=0;i<ansbfs.size();i++)
    {
        cout<<ansbfs[i]<<" ";
    }
    return 0;
}

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int noofenclaves(vector<vector<int>>arr,vector<vector<bool>>&vis,int n,int m)
{
    queue<pair<int,int>>q;
    //First take all the boundary ones
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]==1)
            q.push({0,i});
        if(arr[n-1][i]==1)
            q.push({n-1,i});
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==1)
            q.push({i,0});
        if(arr[i][m-1]==1)
            q.push({i,m-1});
    }
    int deli[]={-1,0,1,0};
    int delj[]={0,1,0,-1};
    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        vis[i][j]=1;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int ni=i+deli[k];
            int nj=j+delj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && arr[ni][nj]==1)
            {
                q.push({ni,nj});
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1 && vis[i][j]==0)
                cnt++;
        }
    }
    return cnt;
}



int main() {
    // Write C++ code here
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    cout<<noofenclaves(arr,vis,n,m);
    //Enclaves are the land portions that cannot have a route to exit out of the boundary of the matrix. 1 is land and 0 is water.
    return 0;
}

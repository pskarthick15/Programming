// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;



vector<vector<int>>nearest1toele(vector<vector<int>>arr,vector<vector<bool>>&vis,int n,int m)
{
    vector<vector<int>>ans(n,vector<int>(m));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                q.push({{i,j},0});// In case if the ele is 1 then push it into the queue
            }
        }
    }
    int deli[]={1,0,-1,0};
    int delj[]={0,1,0,-1};
    
    while(!q.empty())
    {
        int i=q.front().first.first;
        int j=q.front().first.second;
        int dis=q.front().second;
        vis[i][j]=1;
        ans[i][j]=dis;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int ni=i+deli[k];
            int nj=j+delj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && arr[ni][nj]==0)
            {
                q.push({{ni,nj},dis+1});
            }
        }
    }
    return ans;
}




int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    //Distance of nearest cell having 1
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
    vector<vector<int>>ans=nearest1toele(arr,vis,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

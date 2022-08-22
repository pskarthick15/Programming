// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;



vector<vector<int>>updatematrix(vector<vector<int>>&mat)
{
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>ans(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                q.push({{i,j},0});
                ans[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    
    int delx[]={-1,0,1,0};
    int dely[]={0,1,0,-1};
    
    while(!q.empty())
    {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        q.pop();
        ans[x][y]=d;
        for(int k=0;k<4;k++)
        {
            int nx=x+delx[k];
            int ny=y+dely[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny])
            {
                vis[nx][ny]=1;
                q.push({{nx,ny},d+1});
            }
        }
    }
    return ans;
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>ans=updatematrix(mat);
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

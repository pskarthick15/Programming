// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
//No of Islands


void island_bfs(vector<vector<char>>&grid,int n,int m,vector<vector<bool>>&vis,int i,int j)
{
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        //Here we need to check the neighbours that is (row-1,col),(row+1,col),(row,col-1),(row,col+1),(row-1,col-1),(row+1,col+1)
        for(int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++)
            {
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}




int no_of_islands(vector<vector<char>>&grid,int n,int m)
{
    int cnt=0;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='1')//If it is not visited and we see a land then only count amd traverse
            {
                cnt++;
                island_bfs(grid,n,m,vis,i,j);
            }
        }
    }
    return cnt;
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<"No of islands = "<<no_of_islands(grid,n,m);
    return 0;
}

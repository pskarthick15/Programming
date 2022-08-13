// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std; 




void floodfilldfs(vector<vector<int>>&graph,vector<vector<bool>>&vis,int x,int y,int del_x[],int del_y[],int oldcol,int newcol,int n,int m)
{
    vis[x][y]=1;
    graph[x][y]=newcol;
    // For checking its neighbours which are 4 connected and accordingly colouring them also
    for(int i=0;i<4;i++)
    {
        int nx=x+del_x[i];
        int ny=y+del_y[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && graph[nx][ny]==oldcol && !vis[nx][ny])
        {
            graph[nx][ny]=newcol;
            floodfilldfs(graph,vis,nx,ny,del_x,del_y,oldcol,newcol,n,m);
        }
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>graph[i][j];
    }
    int sr,sc;
    cin>>sr>>sc;
    int newcol;
    cin>>newcol;
    
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    // For the neighbours of a given i and j to also be checked and accordingly coloured
    // As we have for a given (i,j) as 4 connected components to be (i-1,j),(i+1,j),(i,j-1),(i,j+1)
    int delta_x[]={-1,0,1,0};
    int delta_y[]={0,1,0,-1};
    int oldcol=graph[sr][sc];
    floodfilldfs(graph,vis,sr,sc,delta_x,delta_y,oldcol,newcol,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

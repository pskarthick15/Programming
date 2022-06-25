// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


void floodfill(vector<vector<int>>& arr,int n,int m,int sr,int sc,int color)
{
    queue<pair<pair<int,int>,int>>q;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    //BFS algorithm
    
    int col=arr[sr][sc];
    q.push({{sr,sc},col});
    while(!q.empty())
    {
        int i=q.front().first.first;
        int j=q.front().first.second;
        int c=q.front().second;
        q.pop();
        vis[i][j]=1;
        if(i>=1 && i<n && j>=0 && j<m && arr[i-1][j]==c && vis[i-1][j]==0)
        {
            q.push({{i-1,j},c});
        }
        if(i>=0 && i<n-1 && j>=0 && j<m && arr[i+1][j]==c && vis[i+1][j]==0)
        {
            q.push({{i+1,j},c});
        }
        if(i>=0 && i<n && j>=1 && j<m && arr[i][j-1]==c && vis[i][j-1]==0)
        {
            q.push({{i,j-1},c});
        }
        if(i>=0 && i<n && j>=0 && j<m-1 && arr[i][j+1]==c && vis[i][j+1]==0)
        {
            q.push({{i,j+1},c});
        }
        arr[i][j]=color;
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr;
    vector<int>k1;
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>k;
            k1.push_back(k);
        }
        arr.push_back(k1);
        k1.clear();
    }
    int sr,sc,color;
    cin>>sr>>sc>>color;
    floodfill(arr,n,m,sr,sc,color);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

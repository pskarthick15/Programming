#include<bits/stdc++.h>
using namespace std;


int largest_square_matrix(vector<vector<int>>&arr,int n,int m)
{
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==1)
        {
            dp[i][0]=1;
        }
        else
        {
            dp[i][0]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]==1)
        {
            dp[0][i]=1;
        }
        else
        {
            dp[0][i]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                dp[i][j]=1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            maxi=max(maxi,dp[i][j]);
        }
    }
    return maxi;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr;
    vector<int>a;
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>k;
            a.push_back(k);
        }
        arr.push_back(a);
        a.clear();
    }
    cout<<largest_square_matrix(arr,n,m);
}
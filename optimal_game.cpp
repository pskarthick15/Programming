#include <bits/stdc++.h>
using namespace std;
int game(vector<int>&arr,int i,int j,int turn,vector<vector<int>>&dp)
{
    if(turn==0)
    {
        if(i==j)
            return arr[i];
        else
        {
            if(dp[turn][i]!=-1)
                return dp[turn][i];
            else if(dp[turn][j]!=-1)
                return dp[turn][j];
            else
            {
                int a=arr[i]+game(arr,i+1,j,1,dp);
                int b=arr[j]+game(arr,i,j-1,1,dp);
                if(a==max(a,b))
                    return dp[turn][i]=a;
                else
                {
                    return dp[turn][j]=b;
                }
        }
    }
    }
    else if(turn==1)
    {
        if(i==j)
            return 0;
        else
        {
            if(dp[turn][i]!=-1)
                return dp[turn][i];
            else if(dp[turn][j]!=-1)
                return dp[turn][j];
            else
            {
                int x=game(arr,i+1,j,0,dp);
                int y=game(arr,i,j-1,0,dp);
                if(x==min(x,y))
                    return dp[turn][i]=x;
                else
                    return dp[turn][j]=y;
            }
        }
    }
}

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<int>games;
    vector<vector<int>>dp(2,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        games.push_back(k);
    }
    cout<<game(games,0,n-1,0,dp);
    //std::cout << "Hello world!";

    return 0;
}
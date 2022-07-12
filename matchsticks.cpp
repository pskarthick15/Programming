// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;


bool formsquare(int arr[],int i,int n,int t,int r,int d,int l,vector<vector<vector<vector<vector<int>>>>>&dp)
{
    if(t==r && r==d && d==l && i==n)
        return true;
    else if(i==n)
        return false;
    else
    {
            if(dp[i][t][r][d][l]!=-1)
                return dp[i][t][r][d][l];
            else
            {
                bool top,right,down,left;
                top=formsquare(arr,i+1,n,t+arr[i],r,d,l,dp);
                right=formsquare(arr,i+1,n,t,r+arr[i],d,l,dp);
                down=formsquare(arr,i+1,n,t,r,d+arr[i],l,dp);
                left=formsquare(arr,i+1,n,t,r,d,l+arr[i],dp);
                if(top || right || down || left)
                {
                    return dp[i][t][r][d][l]=true;
                }
                else
                    return dp[i][t][r][d][l]=false;
            }
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    //Memoization using a 5D array to store the l,r,t and f sums and the return values
    vector<vector<vector<vector<vector<int>>>>>dp(n,vector<vector<vector<vector<int>>>>(sum+1,vector<vector<vector<int>>>(sum+1,vector<vector<int>>(sum+1,vector<int>(sum+1,-1)))));
    cout<<formsquare(arr,0,n,0,0,0,0,dp);
    return 0;
}

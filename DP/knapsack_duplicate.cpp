#include<bits/stdc++.h>
using namespace std;


int knapsack_dup(int val[],int wt[],int n,int i,int w,vector<vector<int>>&mem)
{
    if(w<0 || (i==n && w>0))
        return -1*1e9;
    else if(w==0)
        return 0;
    else
    {
        if(mem[i][w]!=-1)
            return mem[i][w];
        else
        {
            int take=val[i]+knapsack_dup(val,wt,n,i,w-wt[i],mem);
            int nottake=knapsack_dup(val,wt,n,i+1,w,mem);
            return mem[i][w]=max(take,nottake);
        }
    }
}


int main()
{
    int n;
    cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int W;
    cin>>W;
    vector<vector<int>>mem(n,vector<int>(W+1,-1));
    cout<<knapsack_dup(val,wt,n,0,W,mem);
}
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int maxcut(int arr[],int i,int m,int n,vector<vector<int>>&mem)
{
    if(n==0)
    {
        return 0;
    }
    else if((i==m && n>0) || n<0)
    {
        return INT_MIN;
    }
    else
    {
        if(mem[i][n]!=-1)
            return mem[i][n];
        else
        {
            int take=1+maxcut(arr,i,m,n-arr[i],mem);
            int nottake=maxcut(arr,i+1,m,n,mem);
            return mem[i][n]=max(take,nottake);
        }
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    int arr[m];//Array for the available segment lengths
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>>mem(m,vector<int>(n+1,-1));
    cout<<maxcut(arr,0,m,n,mem);// here we have the capability to memoize the changing states of n and also i so that we dont solve repetitive subproblems again and again.
    return 0;
}
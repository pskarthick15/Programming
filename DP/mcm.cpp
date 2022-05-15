// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int mcm(int arr[],int i,int j,vector<vector<int>>&m)
{
    if(i==j)
        return 0;
    else
    {
        if(m[i][j]!=-1)
            return m[i][j];
        else
        {
            int mini=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int op=arr[i-1]*arr[k]*arr[j]+mcm(arr,i,k,m)+mcm(arr,k+1,j,m);
                mini=min(mini,op);
            }
            return m[i][j]=mini;
        }
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    int arr[n];
    vector<vector<int>>m(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<mcm(arr,1,n-1,m);// But now as we have repetitive subproblems to solve can do memoization! Here  i and j have their states to vary from 0 to n-1 so can use them for memoization.
    return 0;
}
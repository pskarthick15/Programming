// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int mini_removals(int arr[],int i,int j,int n,int k,int r,vector<vector<int>>&mem)
{
    if((arr[j]-arr[i]<=k) || i==j || i>j)
    {
        return r;
    }
    else
    {
        if(mem[i][j]!=-1)
            return mem[i][j];
        else
        {
            int takeleft=mini_removals(arr,i+1,j,n,k,r+1,mem);
            int takeright=mini_removals(arr,i,j-1,n,k,r+1,mem);
            return mem[i][j]=min(takeleft,takeright);
        }
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    vector<vector<int>>mem(n,vector<int>(n,-1));
    int k;
    cin>>k;
    cout<<mini_removals(arr,0,n-1,n,k,0,mem);// Now due to overlapping subproblems we can optimize the solution by doing memoization.
    
    return 0;
}
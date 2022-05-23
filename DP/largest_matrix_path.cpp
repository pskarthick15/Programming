// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int max_path_sum(vector<vector<int>>&arr,int i,int j,int n, int m,vector<vector<int>>&mem)
{
    if(i==n)
    {
        return 0;
    }
    else if(j==m || j<0)
    {
        return -1*1e9;
    }
    else
    {
        if(mem[i][j]!=-1)
            return mem[i][j];
        else
        {
            int down=arr[i][j]+max_path_sum(arr,i+1,j,n,m,mem);
            int downleft=arr[i][j]+max_path_sum(arr,i+1,j-1,n,m,mem);
            int downright=arr[i][j]+max_path_sum(arr,i+1,j+1,n,m,mem);
            return mem[i][j]=max((down,downleft),downright);
        }
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    vector<vector<int>>arr;
    vector<int>a;
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>k;
            a.push_back(k);
        }
        arr.push_back(a);
        a.clear();
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int maxi=INT_MIN;
    for(int j=0;j<n;j++)
    {
        maxi=max(maxi,max_path_sum(arr,0,j,n,n,dp));//Now we can memoize the changing states here i.e i and j i->0 to n-1 and j-> 0 to n-1. So we use the n*n dp array.
    }
    cout<<maxi;
    return 0;
}
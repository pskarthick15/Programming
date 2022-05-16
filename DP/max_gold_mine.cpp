// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int goldmine(vector<vector<int>>&arr,int i,int j,int m,int n,vector<vector<int>>&mem)
{
    if(i==n || j==m || i==-1)
    {
        return 0;
    }
    else
    {
        if(mem[i][j]!=-1)
            return mem[i][j];
        else
        {
            int r=arr[i][j]+goldmine(arr,i,j+1,m,n,mem);
            int ru=arr[i][j]+goldmine(arr,i-1,j+1,m,n,mem);
            int rd=arr[i][j]+goldmine(arr,i+1,j+1,m,n,mem);
            return mem[i][j]=max(r,max(ru,rd));
        }
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n>>m;
    int l;
    vector<int>k;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>l;
            k.push_back(l);
        }
        arr.push_back(k);
        k.clear();
    }
    //As any of the 1st col can be starting point try all possibilities
    vector<vector<int>>mem(n,vector<int>(m,-1));
    int maxi=-1;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,goldmine(arr,i,0,m,n,mem));
    }
    cout<<maxi;
    return 0;
}
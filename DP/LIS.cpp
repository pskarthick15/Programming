// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int lis(int arr[],int n,int i,int prev,vector<vector<int>>&mem)
{
    if(i==n)
    {
        return 0;
    }
    if(prev==-1)
    {
        if(mem[i][prev+1]!=-1)
            return mem[i][prev+1];
        else
            return mem[i][prev+1]=1+lis(arr,n,i+1,i,mem);
    }
    else
    {
        //Now we can take only is arr[prev]<arr[i] or if increasing.
        if(mem[i][prev+1]!=-1)
            return mem[i][prev+1];
        else
        {
            int maxi=INT_MIN;
            if(arr[prev]<arr[i])
            {
                int take=1+lis(arr,n,i+1,i,mem);//If we taek the element only previous will change or else it will remain the same.
                int nottake=lis(arr,n,i+1,prev,mem);
                maxi=max(take,nottake);
            }
            else
            {
                int nottake=lis(arr,n,i+1,prev,mem);
                maxi=max(maxi,nottake);
            }
            return mem[i][prev+1]=maxi;
        }
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    int arr[n];
    vector<vector<int>>mem(n,vector<int>(n+1,-1));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<lis(arr,n,0,-1,mem);
    return 0;
}
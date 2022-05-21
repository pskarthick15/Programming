// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int subseqpdt(int arr[],int n,int i,int k,int pdt,vector<vector<int>>&mem)
{
    if(i==n)
    {
        if(pdt<=k)
            return 1;
        else if(pdt>k)
            return 0;
    }
    else
    {
        if(mem[i][pdt]!=-1)
            return mem[i][pdt];
        else
        {
            int take=subseqpdt(arr,n,i+1,k,pdt*arr[i],mem);
            int nottake=subseqpdt(arr,n,i+1,k,pdt,mem);
            return mem[i][pdt]=take+nottake;
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
    int k;
    cin>>k;
    vector<vector<int>>mem(n,vector<int>(k,-1));
    cout<<subseqpdt(arr,n,0,k,1,mem)-1;//Neglecting the case of empty set or subsequence
    return 0;
}

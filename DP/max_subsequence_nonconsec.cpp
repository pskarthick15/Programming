// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int maxsumsubseq(int arr[],int i,int n,vector<int>&p)
{
    if(p.size()>=3)
    {
        for(int i=0;i<=p.size()-3;i++)
        {
            if(arr[i+1]==arr[i]+1 && arr[i+2]==arr[i+1]+1)
            {
                return -1*1e9;
            }
        }
    }
    else if(i==n)
    {
        return 0;
    }
    else
    {
        p.push_back(arr[i]);
        int take=arr[i]+maxsumsubseq(arr,i+1,n,p);
        p.pop_back();
        int nottake=maxsumsubseq(arr,i+1,n,p);
        return max(take,nottake);
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
    vector<int>p;
    cout<<maxsumsubseq(arr,0,n,p);//Neglecting the case of empty set or subsequence
    return 0;
}

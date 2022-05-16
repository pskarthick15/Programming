// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isequalpart(int arr[],int i,int n,int s, int sum,vector<vector<int>>&m)
{
        // code here
        if(sum%2!=0)
            return false;
        if(i==n)
        {
            return false;
        }
        else if(s==sum/2)
            return true;
        else
        {
            if(m[i][s]!=-1)
                return m[i][s];
            else
            {
                bool pick=isequalpart(arr,i+1,n,s+arr[i],sum,m);
                bool notpick=isequalpart(arr,i+1,n,s,sum,m);
                return m[i][s]=(pick || notpick);
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
    vector<vector<int>>m(n,vector<int>(sum+1,-1));
    if(isequalpart(arr,0,n,0,sum,m))// Now as we have repeated subproblems we can memoize the repetitive subproblems and store and return them as and when we need
        cout<<"YES";
    else
    {
        cout<<"NO";
    }
    return 0;
}
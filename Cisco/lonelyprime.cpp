// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        int k=i*(n/i);
        if(k==n)
            return false;
    }
    return true;
}
int lonelyprime(int arr[],int n)
{
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        if(isprime(arr[i]))
        {
            m[arr[i]]++;
        }
    }
    for(auto it:m)
    {
        if(it.second==1)
            return it.first;
    }
    return -1;
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
    cout<<lonelyprime(arr,n);
    return 0;
}

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int maxpdt(vector<int>arr)
{
    int pdt=1,maxi=1;
    for(int i=0;i<arr.size();i++)
    {
        int t=pdt*arr[i];
        if(t>0)
        {
            pdt*=arr[i];
        }
        else if(t==0)
        {
            continue;
        }
        else//if t<0
        {
            if(i+1<arr.size() && arr[i+1]<0)
            {
                pdt*=arr[i]*arr[i+1];
                i+1;
            }
            else
            {
                pdt=1;
            }
        }
        maxi=max(maxi,pdt);
    }
    return maxi;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxpdt(arr);
    return 0;
}

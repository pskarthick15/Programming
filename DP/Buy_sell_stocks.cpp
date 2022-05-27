// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int stock_buy_sell(int arr[],int n,int i,bool buy,int k,vector<vector<int>>&mem)
{
    if(k==0 || i==n)
        return 0;
    else
    {
        if(mem[i][buy]!=-1)
            return mem[i][buy];
        else
        {
            if(buy==1)
            {
                int take=-1*arr[i]+stock_buy_sell(arr,n,i+1,0,k,mem);
                int nottake=stock_buy_sell(arr,n,i+1,1,k,mem);
                return mem[i][buy]=max(take,nottake);
            }
            else if(buy==0)
            {
                int take=arr[i]+stock_buy_sell(arr,n,i+1,1,k-1,mem);
                int nottake=stock_buy_sell(arr,n,i+1,0,k,mem);
                return mem[i][buy]=max(take,nottake);
            }
        }
    }
}
//Now we need to make sure that every time we sell the items we need to decrement value of k and if k becomes 0, then just return the profit.
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
    vector<vector<int>>mem(n,vector<int>(2,-1));
    cout<<stock_buy_sell(arr,n,0,1,2,mem);
    return 0;
}
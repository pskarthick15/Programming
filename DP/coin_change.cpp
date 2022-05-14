// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int i, int amount,vector<int>&m)
{
        
        if(amount==0)
        {
            return 0;
        }
        else if(amount<0 || i==coins.size())
        {
            return 1e9;
        }
        else
        {
            if(m[amount]!=-1)
            {
                return m[amount];
            }
            else
            {
                int pick=1+coinChange(coins,i,amount-coins[i],m);
                int notpick=coinChange(coins,i+1,amount,m);
                return m[amount]=min(pick,notpick);
            }
        }
    }
int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    vector<int>v;
    int l;
    for(int i=0;i<n;i++)
    {
        cin>>l;
        v.push_back(l);
    }
    int amt;
    cin>>amt;
    vector<int>m(amt+1,-1);
    int k=coinChange(v,0,amt,m);//But now the variabe changing here is index i so need to memoizde it.
    if(k>=1e9)
    {
        cout<<"-1";
    }
    else
    {
        cout<<k;
    }
    return 0;
}

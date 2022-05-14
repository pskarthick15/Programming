// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int i, int n,vector<vector<int>>&m) 
{ 
       // Your code here
       if(i==n)
            return 0;
       else if(wt[i]>W)//If wt[i]>W then obviously we cant pick it. So move to next.
       {
           if(m[i][W]!=-1)
           {
               return m[i][W];
           }
            return m[i][W]=knapSack(W,wt,val,i+1,n,m);
       }
       else if(wt[i]<=W && i<n)
       {
           if(m[i][W]!=-1)
           {
               return m[i][W];
           }
           else
           {
                int pick=val[i]+knapSack(W-wt[i],wt,val,i+1,n,m);
                int notpick=knapSack(W,wt,val,i+1,n,m);
                return m[i][W]=max(pick,notpick);
            }    
       }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int W;
    cin>>W;
    vector<vector<int>>m(n,vector<int>(W+1,-1));
    cout<<knapSack(W,wt,val,0,n,m);
    return 0;
}

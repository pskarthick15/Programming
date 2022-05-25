// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int game_reach(int arr[],int i,int s,vector<vector<int>>&mem)
{
    if((s>0 && i==3) || s<0)
        return 0;
    else if(s==0)
        return 1;
    else
    {
        if(mem[s][i]!=-1)
            return mem[s][i];
        else
        {
            int take=game_reach(arr,i,s-arr[i],mem);
            int nottake=game_reach(arr,i+1,s,mem);
            return mem[s][i]=take+nottake;
        }
    }
}

int main() {
    // Write C++ code here
    int s,t;
    cin>>t;
    while(t>0)
    {
        cin>>s;
        int arr[3];
        arr[0]=3,arr[1]=5,arr[2]=10;
        // As we are solving repetitive subproblems again and again we can do memoization to bring down the time complexity.
        vector<vector<int>>mem(s+1,vector<int>(3,-1));
        cout<<game_reach(arr,0,s,mem)<<endl;
        t--;
    }
        return 0;
}
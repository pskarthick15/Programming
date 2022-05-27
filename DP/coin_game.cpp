// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int coin_game(int arr[],int i,int j,int n,int turn,vector<vector<vector<int>>>&mem)
{
    if(turn == 0)//If As turn
    {
        if(mem[n][i][j]!=-1)
            return mem[n][i][j];
        else
        {
            if(i==3 || n<0)
                return -1;
            else if(arr[i]==n)
                return turn;
            else
            {
                int t=coin_game(arr,i,j,n-arr[i],1,mem);
                int dt=coin_game(arr,i+1,j,n,0,mem);
                if(t!=-1)
                     mem[n][i][j]=t;
                else if(dt!=-1)
                    mem[n][i][j]=dt;
                return mem[n][i][j];
            }
        }
    }
    else if(turn == 1)//If its Bs turn
    {
        if(mem[i][j]!=-1)
            return mem[n][i][j];
        else
        {
            if(j==3 || n<0)
                return -1;
            else if(arr[j]==n)
                return turn;
            else
            {
                int t=coin_game(arr,i,j,n-arr[j],0,mem);
                int dt=coin_game(arr,i,j+1,n,1,mem);
                if(t!=-1)
                    mem[n][i][j]=t;
                else if(dt!=-1)
                    mem[n][i][j]=dt;
                return mem[n][i][j];
            }
        }
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,x,y;
    cin>>n>>x>>y;
    int arr[3];
    arr[0]=1;
    arr[1]=x;
    arr[2]=y;
    //Now lets do the memoization for avoiding calculation of repeated subproblems again and again.
    vector<vector<vector<int>>>mem(n,vector<vector<int>>(3,vector<int>(3,-1)));
    if(coin_game(arr,0,0,n,0,mem))
        cout<<"B";
    else
        cout<<"A";
    return 0;
}
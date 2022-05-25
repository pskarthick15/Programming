#include<bits/stdc++.h>
using namespace std;


bool word_break(string A,vector<string>&B,int i,int j,vector<vector<int>>&mem)
{
    if(find(B.begin(),B.end(),A.substr(i,j-i+1))!=B.end())
        return true;
    else if(find(B.begin(),B.end(),A.substr(i,j-i+1))==B.end() && i==j) //We are left with a single charcter and still we are unable to find a match. 
    {
        return false;
    }
    else
    {
        if(mem[i][j]!=-1)
            return mem[i][j];
        else
        {
            bool consolidate=false;
            for(int k=i;k<j;k++)
            {
                bool left=word_break(A,B,i,k,mem);
                bool right=word_break(A,B,k+1,j,mem);
                if(left && right)
                {
                    consolidate=true;
                    break;
                }
            }
            return mem[i][j]=consolidate;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    vector<string>B;//Dictionary
    string A;
    string k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        B.push_back(k);
    }
    cin>>A;
    //Now instead of solving repeated subproblems again and again lets use memoization.
    int m=A.size();
    vector<vector<int>>mem(m,vector<int>(m,-1));
    if(word_break(A,B,0,m-1,mem))
    {
        cout<<"1";
    }
    else
        cout<<"0";
}
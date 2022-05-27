// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool wild_pattern(string s1,string s2,int n,int m,int i,int j,vector<vector<int>>&mem)
{
    //Base cases
    if(i==n && j==m)//Both of them end together after all matches
    {
        return true;
    }
    else if(i==n && j<m)
        return false;
    else if(i<n && j==m)
    {
        for(int ind=i;ind<n;ind++)//If pattern remain and string exhausted only 1 case possible if pattern has remaining all as *
        {
            if(s1[ind]!='*')
                return false;
        }
        return true;
    }
    //Recursion cases
    if(mem[i][j]!=-1)
        return mem[i][j];
    else
    {
        if(s1[i]==s2[j] || s1[i]=='?')
        {
            return mem[i][j]=wild_pattern(s1,s2,n,m,i+1,j+1,mem);
        }
        else if(s1[i]=='*')
        {
            return mem[i][j]=wild_pattern(s1,s2,n,m,i+1,j,mem) || wild_pattern(s1,s2,n,m,i,j+1,mem);
        }
        else
            return false;
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    string pattern,word;
    cin>>pattern>>word;
    int n=pattern.size(),m=word.size();//Now we can do memoization to avoid solving repetitive subproblems
    vector<vector<int>>mem(n,vector<int>(m,-1));
    cout<<wild_pattern(pattern,word,n,m,0,0,mem);
    return 0;
}
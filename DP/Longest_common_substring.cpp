// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int lcsub(string s1,string s2)
{
    int n=s1.size(),m=s2.size();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<m+1;j++)
    {
        dp[0][j]=0;
    }
    int ans=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j]=0;
            
        }
    }
    return ans;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    //Now this is actually similar to that of LCS but the only catch here is that we need to have the matching characters to be conecutive. So to ensure that we keep track of a state variable c which is true if consecutiveness maintained and false the otherwise.
    string s1,s2;
    cin>>s1>>s2;
    // Now let us do memoization to keep track of repeating subproblems.
    cout<<lcsub(s1,s2);
    return 0;
}
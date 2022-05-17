
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2,int i,int j,vector<vector<int>>&mem)
{
        // your code here
        if(i==s1.size() || j==s2.size())
        {
            return 0;
        }
        else if(s1[i]==s2[j])
        {
            if(mem[i][j]!=-1)
                return mem[i][j];
            else
            {
                return mem[i][j]=1+lcs(s1,s2,i+1,j+1,mem);
            }
        }
        else
        {
            if(mem[i][j]!=-1)
                return mem[i][j];
            else
            {
                int left=lcs(s1,s2,i+1,j,mem);
                int right=lcs(s1,s2,i,j+1,mem);
                return mem[i][j]=max(left,right);
            }
        }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>>mem(s1.size(),vector<int>(s2.size(),-1));
    cout<<lcs(s1,s2,0,0,mem);
    /*Now as we have the state variables i and j to be changing from 0 to s1.size()-1 and 0 to s2.size()-1 respectively we can memoize the variables.*/
    return 0;
}
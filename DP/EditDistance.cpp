// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int editdist(string s,string t,int i,int j,vector<vector<int>>&m)
    {
        if(i==s.size() && j==t.size())
            return 0;
        else if(s[i]==t[j])
        {
            if(m[i][j]!=-1)
                return m[i][j];
            else
                return m[i][j]=editdist(s,t,i+1,j+1,m);
        }
        else if(j==t.size() && i<s.size())
            return s.size()-i;
        else if(i==s.size() && j<t.size())
        {
            return t.size()-j;
        }
        else if(i<s.size() && j<t.size())
        {
            if(m[i][j]!=-1)
                return m[i][j];
            else
            {
                int insert=1+editdist(s,t,i,j+1,m);
                int rem=1+editdist(s,t,i+1,j,m);
                int replace=1+editdist(s,t,i+1,j+1,m);
                return m[i][j]=min(min(insert,rem),replace);
            }
        }
    }

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    string s1,s2;
    cin>>s1>>s2;
    // Now a cahnce to memoize the states of i and j as repeated subproblems arise in the recursion tree. As i has 0 to s1.size()-1 and j has 0 to s2.size()-1 states.
    vector<vector<int>>m(s1.size(),vector<int>(s2.size(),-1));
    cout<<editdist(s1,s2,0,0,m);
    return 0;
}
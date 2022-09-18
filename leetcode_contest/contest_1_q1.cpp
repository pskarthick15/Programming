// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


vector<int>prefix_score(vector<string>words)
{
    map<string,int>m;
    vector<int>ans;
    for(int i=0;i<words.size();i++)
    {
        string str="";
        for(int j=0;j<words[i].size();j++)
        {
            str+=words[i][j];
            m[str]++;
        }
    }
    for(int i=0;i<words.size();i++)
    {
        string str="";
        int tot=0;
        for(int j=0;j<words[i].size();j++)
        {
            str+=words[i][j];
            tot+=m[str];
        }
        ans.push_back(tot);
    }
    return ans;
}

//Time Complexity is O(N*M)
int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    vector<int>ans=prefix_score(s);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

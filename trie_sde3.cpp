// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node* links[26];
    vector<int>prefix;
}Node;

class trie
{
    private: 
        Node* root=new Node();
    public:
        trie()
        {
            for(int i=0;i<26;i++)
            {
                root->links[i]=NULL;
            }
        }
        void insert(string word,int ind)
        {
            Node* ptr=root;
            for(int i=0;i<word.size();i++)
            {
                if(ptr->links[word[i]-'a']==NULL)
                {
                    ptr->links[word[i]-'a']=new Node();
                }
                ptr=ptr->links[word[i]-'a'];
                ptr->prefix.push_back(ind);
            }
        }
        vector<int>dict_prefix(string word)
        {
            vector<int>ans;
            Node* ptr=root;
            bool flag=false;
            for(int i=0;i<word.size();i++)
            {
                if(ptr->links[word[i]-'a']!=NULL)
                {
                    ptr=ptr->links[word[i]-'a'];
                }
                else
                {
                    ans.push_back(-1);
                    flag=true;
                    break;
                }
            }
            if(flag==true)
            {
                return ans;
            }
            else
            {
                return ptr->prefix;
            }
        }
        
};




int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    string s[n];
    trie t;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        t.insert(s[i],i);
    }
    string st;
    cin>>st;
    string str="";
    int i=0;
   for(int i=0;i<st.size();i++)
   {
       str+=st[i];
       vector<int>a=t.dict_prefix(str);
        if(a.size()==1 && a[0]==-1)
            cout<<"0";
        else
        {
            for(int j=0;j<a.size();j++)
            {
                cout<<s[a[j]]<<" ";
            }
        }
        cout<<endl;
   }
    return 0;
}
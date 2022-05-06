// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node* links[26];
    bool flag;
}Node;

//Program to find longest word with all the prefixes
class trie
{
    private: Node* root=new Node();
    public: 
            trie()
            {
                for(int i=0;i<26;i++)
                {
                    root->links[i]=NULL;
                }
                root->flag=false;
            }
            void insert(string word)
            {
                Node* ptr=root;
                for(int i=0;i<word.size();i++)
                {
                    if(ptr->links[word[i]-'a']==NULL)
                    {
                        ptr->links[word[i]-'a']=new Node();
                        ptr=ptr->links[word[i]-'a'];
                    }
                    else
                    {
                        ptr=ptr->links[word[i]-'a'];
                    }
                }
                ptr->flag=true;
            }
            string longestword(string word)
            {
                Node* ptr=root;
                string str="";
                for(int i=0;i<word.size();i++)
                {
                        if(ptr->links[word[i]-'a']!=NULL && ptr->links[word[i]-'a']->flag==true)
                        {
                            str+='a'+ (word[i]-'a');
                            ptr=ptr->links[word[i]-'a'];
                        }
                }
                return str;
            }
};


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    cout<<"Enter array of strings\n";
    string s[n];
    trie t;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        t.insert(s[i]);
    }
    string lw="";
    string lw1;
    for(int i=0;i<n;i++)
    {
        lw1=t.longestword(s[i]);
        if(lw1.size()>lw.size())
        {
            lw=lw1;
        }
    }
    cout<<"The longest prefix word in given set of strings is:"<<lw;
    return 0;
}
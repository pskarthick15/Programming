// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node* links[26];
    bool eow;
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
            root->eow=false;
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
            ptr->eow=true;
        }
        bool is_containedin_dict(string word)
        {
            Node* ptr=root;
            for(int i=0;i<word.size();i++)
            {
                if(ptr->links[word[i]-'a']==NULL)
                {
                    return false;
                }
                else
                {
                    if(ptr->links[word[i]-'a']->eow)
                    {
                        if(i==word.size()-1)
                            return true;
                        else
                        {
                            ptr=root;
                            continue;
                        }
                    }
                    else
                    {
                        ptr=ptr->links[word[i]-'a'];
                    }
                }
            }
            return false;
        }
        
};

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    string dict[n];
    trie t;
    for(int i=0;i<n;i++)
    {
        cin>>dict[i];
        t.insert(dict[i]);
    }
    string s;
    cin>>s;
    if(t.is_containedin_dict(s))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
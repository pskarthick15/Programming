// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node* links[26];
    int cnt;//To keep track of the inserted letters of every word
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
            root->cnt=0;
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
                ptr->cnt++;
            }
        }
        string unique_prefix(string word)
        {
            string str="";
            Node* ptr=root;
            for(int i=0;i<word.size();i++)
            {
                str+=word[i];
                if(ptr->links[word[i]-'a']->cnt>1)// If the reference of a given letter in trie has more than a letter then from that letter we can go to many references. So in this case move to next one for uniquness
                {
                    ptr=ptr->links[word[i]-'a'];
                }
                else
                {
                    break;
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
    string s[n];
    trie t;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        t.insert(s[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<t.unique_prefix(s[i])<<" ";
    }
    return 0;
}
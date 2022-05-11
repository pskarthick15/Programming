// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
       node* links[26];
}Node;


class trie
{
    private: 
        Node* root = new Node();
    public:
        trie()
        {
            for(int i=0;i<26;i++)
            {
                root->links[i]=NULL;
            }
        }
        int insert(string word)
        {
            int count_sub=0;
            Node* ptr=root;
            for(int i=0;i<word.size();i++)
            {
                if(ptr->links[word[i]-'a']==NULL)
                {
                    ptr->links[word[i]-'a']=new Node();
                    ptr=ptr->links[word[i]-'a'];
                    count_sub++;
                }
                else
                {
                    ptr=ptr->links[word[i]-'a'];
                }
            }
            return count_sub;
        }
};




int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    string str;
    cin>>str;
    trie t;
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        int count_sub=0;
        for(int j=i;j<str.size();j++)
        {
            count_sub+=t.insert(str.substr(i,j-i+1));
        }
        count+=count_sub;
    }
    cout<<count;
    return 0;
}
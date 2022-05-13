// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


typedef struct node
{
    node* links[2];
    bool visited;
}Node;

class trie
{
    private:
        Node* root=new Node();
    public:
        trie()
        {
            root->links[0]=NULL;
            root->links[1]=NULL;
            root->visited=false;
        }
        void insert(vector<int>word)
        {
            Node* ptr=root;
            for(int i=0;i<word.size();i++)
            {
                if(ptr->links[word[i]]==NULL)
                {
                    ptr->links[word[i]]=new Node();
                }
                ptr=ptr->links[word[i]];
            }
        }
        vector<int>unique_rows(vector<int>word)
        {
            Node* ptr=root;
            vector<int>ans;
            for(int i=0;i<word.size();i++)
            {
                if(ptr->links[word[i]]!=NULL)
                {
                    ptr=ptr->links[word[i]];
                }
            }
            if(ptr->visited==false)
            {
                ptr->visited=true;
                return word;
            }
            else
            {
                ans.push_back(-1);
                return ans;
            }
        }
};


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr;
    vector<int>k;
    trie t;
    int l;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>l;
            k.push_back(l);
        }
        arr.push_back(k);
        t.insert(k);
        k.clear();
    }

    for(int i=0;i<m;i++)
    {
        vector<int>a=t.unique_rows(arr[i]);
        if(!(a.size()==1 && a[0]==-1))
        {
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
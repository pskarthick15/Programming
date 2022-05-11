// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


typedef struct node
{
    node* links[2];
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
        }
        
        void insert(int num)
        {
            Node* ptr=root;
            for(int i=31;i>=0;i--)// Bcs we want to check if each of the 32 bits are set or not
            {
                int bit=(num>>i)&1;
                if(!ptr->links[bit])
                {
                    ptr->links[bit]=new Node();
                }
                ptr=ptr->links[bit];
            }
        }
        
        int getmax(int num)
        {
            Node* ptr=root;
            int maxnum=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(ptr->links[1-bit]!=NULL)
                {
                    maxnum=maxnum|(1<<i);//If the opposite bit is present the take it or add it to our answer
                    ptr=ptr->links[1-bit];
                }
                else
                {
                    ptr=ptr->links[bit];
                }
            }
            return maxnum;
        }
        
};





int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n,m;
    cin>>n;
    trie t;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
        t.insert(arr1[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int maxi=0;
    int maxnum;
    for(int i=0;i<m;i++)
    {
        maxnum=t.getmax(arr2[i]);
        if(maxnum>maxi)
            maxi=maxnum;
    }
    cout<<maxi;
    return 0;
}
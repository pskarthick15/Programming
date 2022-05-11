// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
   
// Online C++ compiler to run C++ program online


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

bool compare(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
{
    if(a.second.second < b.second.second)
        return true;
    else
        return false;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l;
    cin>>l;
    int q[l][2];
    vector<pair<int,pair<int,int>>>p;
    for(int i=0;i<l;i++)
    {
       cin>>q[i][0];
       cin>>q[i][1];
       p.push_back({i,{q[i][0],q[i][1]}});
    }
    sort(p.begin(),p.end(),compare);
    trie t;
    vector<int>ans(l,0);
    int j=0;
    for(int i=0;i<l;i++)
    {
        
        int qind=p[i].first;
        while(j<n && arr[j]<=p[i].second.second)
        {
            t.insert(arr[j]);
            j++;
        }
        if(j==0)
        {
            ans[qind]=-1;
        }
        else
        {
            ans[qind]=t.getmax(p[i].second.first);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
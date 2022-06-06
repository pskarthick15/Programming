// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node *left,*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
}Node;


vector<int>topview(Node*root,int level,int vertical)
{
    vector<int>ans;
    if(root==NULL)
        return ans;
    else
    {
        map<int,Node*>m;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{level,vertical}});
        while(!q.empty())
        {
            int v=q.front().second.second;
            int l=q.front().second.first;
            Node* node=q.front().first;
            q.pop();
            if(m.find(v)==m.end())// If not already present
            {
                m[v]=node;
            }
            if(node->left)
            {
                q.push({node->left,{l+1,v-1}});
            }
            if(node->right)
            {
                q.push({node->right,{l+1,v+1}});
            }
        }
        auto it=m.begin();
        while(it!=m.end())
        {
            ans.push_back(it->second->data);
            it++;
        }
        return ans;
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(6);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->left->left->right=new Node(8);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);
    vector<int>a=topview(root2,0,0);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    //print_inorder(root1);
    return 0;
}

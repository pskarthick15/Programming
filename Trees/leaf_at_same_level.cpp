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

void leaf_vector(Node*root,int level,vector<int>&v)
{
    if(root->left==NULL && root->right==NULL)
        v.push_back(level);
    else if(root==NULL)
    {
        return;
    }
    else
    {
        leaf_vector(root->left,level+1,v);
        leaf_vector(root->right,level+1,v);
    }
}

bool check(Node*root)
{
    vector<int>ans;
    leaf_vector(root,0,ans);
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i]!=ans[i-1])
            return false;
    }
    return true;
}

void print_preorder(Node*root)
{
    if(root==NULL)
        return;
    else
    {
        cout<<root->data<<" ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    Node *root1=new Node(10);
    root1->left=new Node(20);
    root1->right=new Node(30);
    root1->left->left=new Node(10);
    root1->left->right=new Node(15);
    cout<<check(root)<<endl;
    cout<<check(root1)<<endl;
    return 0;
}

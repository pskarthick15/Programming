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


Node* build(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&inMap)
{
    if(prestart>preend || instart>inend)
        return NULL;
    Node*root=new Node(preorder[prestart]);
    int inroot=inMap[root->data];//Checking the root of preorder in inorder
    int numsleft=inroot-instart;
    root->left=build(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inMap);
    root->right=build(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inMap);
    return root;
}

Node*buildtree(vector<int>&preorder,vector<int>&inorder)
{
    map<int,int>inMap;//An inorder map for hashing to find the root from preorder where it is in the inorder
    for(int i=0;i<inorder.size();i++)
    {
        inMap[preorder[i]]=i;
    }
    Node*root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
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
    int n;
    cin>>n;
    vector<int>preorder;
     vector<int>inorder;
    int k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        inorder.push_back(k);
    }
    for(int i=0;i<n;i++)
    {
        cin>>k;
        preorder.push_back(k);
    }
        
    Node*root=buildtree(preorder,inorder);
    print_preorder(root);
    return 0;
}

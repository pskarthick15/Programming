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

bool ismirror(Node*root1,Node*root2)
{
    if(root1==NULL)
        return (root2==NULL);
    else
    {
        if(root1->data == root2->data)
            return (ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left));
        else
            return false;
    }
}

Node* formtree(vector<int>&A,vector<int>&B,int n,int e)
{
    
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
    Node *root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    
    Node *root2=new Node(1);
    root2->left=new Node(3);
    root2->right=new Node(2);
    
    cout<<ismirror(root1,root2);
    
    return 0;
}

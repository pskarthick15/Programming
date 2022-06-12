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

Node* LCA(Node*root,int n1,int n2)
{
    if(root==NULL || root->data==n1 ||root->data==n2)
        return root;
    else
    {
        Node*l=LCA(root->left,n1,n2);
        Node*r=LCA(root->right,n1,n2);
        if(l && r)  
            return root;
        else if(l)
            return l;
        else if(r)
            return r;
        else
            return NULL;
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(5);
    root1->left=new Node(2);
    root1->left->left=new Node(3);
    root1->left->right=new Node(4);
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    
    int n1=3,n2=4,n3=2,n4=3;
    Node*lca1=LCA(root1,n1,n2);
    Node*lca2=LCA(root2,n3,n4);
    cout<<lca1->data<<" "<<lca2->data;
    return 0;
}

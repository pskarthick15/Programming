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

int largestsubtreesum(Node*root,int &maxi)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return root->data;
    else
    {
        int l=largestsubtreesum(root->left,maxi);
        int r=largestsubtreesum(root->right,maxi);
        maxi=max(maxi,root->data+l+r);
        return root->data+l+r;
    }
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
    root1->left->left=new Node(4);
    root1->left->right=new Node(5);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);
    
    Node *root2=new Node(1);
    root2->left=new Node(-2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->right->left=new Node(-6);
    root2->right->right=new Node(2);
    
    int maxi1=INT_MIN;
    int maxi2=INT_MIN;
    int k1=largestsubtreesum(root1,maxi1);
    int k2=largestsubtreesum(root2,maxi2);
    cout<<maxi1<<"\n"<<maxi2;
    
    return 0;
}

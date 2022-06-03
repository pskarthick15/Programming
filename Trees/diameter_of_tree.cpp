// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node*left,*right;
    node(int val)
    {
        data=val;
        left=NULL,right=NULL;
    }
}Node;

int diameter(Node* root,int &maxi)
{
    if(root==NULL)
        return 0;
    else
    {
        int lh=diameter(root->left,maxi);
        int rh=diameter(root->right,maxi);
        maxi=max(maxi,lh+rh);//Here lh + rh is the longest distance passing through that node. So max for all such nodes is the diameter.
        return 1+max(lh,rh);
    }
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(10);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    root->left->right->right=new Node(7);
    int maxi=0;
    cout<<diameter(root,maxi);
    return 0;
}
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

bool isbst(Node*root,int lower,int higher,int &size,int &maxi)
{
    if(root==NULL)
        return true;
    else if(root->left==NULL && root->right==NULL)
    {
        if(root->data>=lower && root->data<=higher)
        {
            size+=1;
            return true;
        }
        else
            return false;
    }
    else
    {
        bool l=isbst(root->left,lower,root->data,size,maxi);
        if(l)
        {
            maxi=max(maxi,size);
        }
        bool r=isbst(root->right,root->data,higher,size,maxi);
        if(r)
        {
            maxi=max(maxi,size);
        }
        if(l&&r)
        {
            size+=1;  
            maxi=max(maxi,size);
            return l&&r;
        }
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(7);
    root1->left=new Node(4);
    root1->right=new Node(6);
    root1->left->right=new Node(9);
    int maxi=0;
    int size=0;
    bool t=isbst(root1,INT_MIN,INT_MAX,size,maxi);
    cout<<maxi;
    return 0;
}

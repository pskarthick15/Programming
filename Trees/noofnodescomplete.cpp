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


int leftheight(Node*root)
{
    int h=0;
    Node*node=root;
    while(node)
    {
        h++;
        node=node->left;
    }
    return h;
}

int rightheight(Node*root)
{
    int h=0;
    Node*node=root;
    while(node)
    {
        h++;
        node=node->right;
    }
    return h;
}

int noofnodescomplete(Node*root)
{
    if(root==NULL)
        return 0;
    else
    {
        int l=leftheight(root);
        int r=rightheight(root);
        if(l==r)
            return pow(2,l)-1;
        else
        {
            return 1+noofnodescomplete(root->left)+noofnodescomplete(root->right);
        }
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
    root1->left->right=new Node(5);
    root1->left->left->left=new Node(8);
    root1->left->left->right=new Node(9);
    root1->left->right->left=new Node(10);
    root1->left->right->right=new Node(11);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);
    cout<<noofnodescomplete(root1);
    return 0;
}

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


void print_inorder(Node*root,int l,int h,int &sum)
{
    if(root==NULL)
        return;
    else
    {
        print_inorder(root->left,l,h,sum);
        if(root->data>=l && root->data<=h)
        {
            sum+=1;
        }
        print_inorder(root->right,l,h,sum);
    }
}

int nodesinrange(Node*root,int l,int h)
{
    int sum=0;
    print_inorder(root,l,h,sum);
    return sum;
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(10);
    root1->left=new Node(5);
    root1->right=new Node(50);
    root1->left->left=new Node(1);
    root1->right->left=new Node(40);
    root1->right->right=new Node(100);
    
    Node *root2=new Node(5);
    root2->left=new Node(4);
    root2->right=new Node(6);
    root2->left->left=new Node(3);
    root2->right->right=new Node(7);
    
    int l=5,h=45;
    int k=nodesinrange(root1,l,h);
    int l1=2,h1=8;
    int k1=nodesinrange(root2,l1,h1);
    cout<<k<<" "<<k1;
    return 0;
}

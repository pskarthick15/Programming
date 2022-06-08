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

Node* sumtree(Node*root)
{
    if(root->left==NULL && root->right==NULL)
    {
        Node*temp=new Node(root->data);
        root->data=0;
        return temp;
    }
    else
    {
        Node*l=NULL;
        Node*r=NULL;
        int s=0;
        if(root->left)
        {
            l=sumtree(root->left);
        }
        if(root->right)
        {
            r=sumtree(root->right);
        }
        if(l!=NULL)
            s+=l->data;
        if(r!=NULL)
            s+=r->data;
        int temp=root->data + s;
        root->data=s;
        Node* t=new Node(temp);
        return t;
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
    Node *root1=new Node(10);
    root1->left=new Node(-2);
    root1->right=new Node(6);
    root1->left->left=new Node(8);
    root1->left->right=new Node(-4);
    root1->right->left=new Node(7);
    root1->right->right=new Node(5);
    Node* root=sumtree(root1);
    print_preorder(root1);
    return 0;
}

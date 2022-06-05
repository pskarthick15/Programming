// Online C++ compiler to run C++ program online
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

Node* mirror(Node *root1)
{
    if(root1==NULL)
    {
        return NULL;
    }
    else
    {
        Node *t=root1->left;
        root1->left=root1->right;
        root1->right=t;
        if(root1->left)
        {
            mirror(root1->left);
        }
        if(root1->right)
        {
            mirror(root1->right);
        }
        return root1;
    }
}

void print_inorder(Node *root)
{
    if(root==NULL)
        return;
    else
    {
        print_inorder(root->left);
        cout<<root->data;
        print_inorder(root->right);
    }
}



int main() {
    // Write C++ code here
    //std::cout << "Hello world!"
    Node *root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(6);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    mirror(root1);
    print_inorder(root1);
    return 0;
}

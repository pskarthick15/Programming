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

Node* helper(Node*node)
{
    if(!node->left && !node->right)
    {
        node=NULL;
        return node;
    }
    else if(node->left)
    {
        Node*next=node->left;
        while(next->right)
            next=next->right;
        node->data=next->data;
        next=NULL;
        return node;
    }
    else
    {
        Node*temp=node;
        node=node->right;
        delete(temp);
        return node;
    }
}


Node* deletebst(Node*root,Node*curr,Node*prev,int &val)
{
    if(curr->data==val)
    {
        if(prev->left==curr)
        {
            prev->left=helper(curr);
        }
        else if(prev->right==curr)
        {
            prev->right=helper(curr);
        }
        return root;
    }
    else
    {
        if(val>curr->data)
            return deletebst(root,curr->right,curr,val);
        else
            return deletebst(root,curr->left,curr,val);
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
    Node *root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(6);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    root1->right->right=new Node(7);
    print_preorder(root1);
    cout<<endl;
    int val=3;
    Node* root=deletebst(root1,root1,NULL,val);
    print_preorder(root);
    cout<<endl;
    return 0;
}

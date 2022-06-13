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

void predsuc(Node*root,Node*&pre,Node*&suc,int key)
{
    if(root==NULL) return;
    if(root->data > key)
    {
        suc= root;
        predsuc(root->left,pre,suc,key);
    }
    else if(root->data <key)
    {
        pre= root;
        predsuc(root->right,pre,suc,key);
    }
    else
    {
        predsuc(root->left,pre,suc,key);
        predsuc(root->right,pre,suc,key);
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
    Node *root1=new Node(50);
    root1->left=new Node(30);
    root1->right=new Node(70);
    root1->left->left=new Node(20);
    root1->left->right=new Node(40);
    root1->right->left=new Node(60);
    root1->right->right=new Node(80);
    int val=100;
    Node*p=NULL,*s=NULL;
    predsuc(root1,p,s,val);
    if(p==NULL)
        p->data=-1;
    if(s==NULL)
        s->data=-1;
    cout<<p->data<<" "<<s->data<<endl;
    return 0;
}

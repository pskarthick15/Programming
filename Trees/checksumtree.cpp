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


int sumtree(Node*root)
{
    if(root->left==NULL && root->right==NULL)
        return root->data;
    else if(root==NULL)
        return 0;
    else
    {
        int l=0,r=0;
        if(root->left)
        {
            l=sumtree(root->left);
        }
        if(root->right)
        {
            r=sumtree(root->right);
        }
        if(root->data==(l+r))
            return 2*(root->data);
        else if(l==-1 || r==-1)
            return -1;
        else
            return -1;
        
            
        }
    }

bool isSumTree(Node* root)
{
         // Your code here
         if(sumtree(root)!=-1)
            return true;
        else
            return false;
}

void print_postorder(Node*root)
{
    if(root==NULL)
        return;
    else
    {
        print_postorder(root->left);
        print_postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node*root1=new Node(62);
    root1->left=new Node(16);
    root1->right=new Node(15);
    root1->left->right=new Node(8);
    root1->left->right->right=new Node(8);
    root1->right->left=new Node(4);
    root1->right->right=new Node(7);
    Node*root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(10);
    root->left->right=new Node(10);
    cout<<sumtree(root1)<<endl;
    cout<<isSumTree(root1);
    return 0;
}

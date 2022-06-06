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


int height(Node*root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh==-1 || rh==-1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        else
            return 1+max(lh,rh);
    }
}

bool balanced(Node*root)
{
    if(height(root)!=-1)
        return true;
    else
        return false;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(6);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->left->left->right=new Node(8);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);
    vector<int>a=zigzag(root2);
    //for(int i=0;i<a.size();i++)
        //cout<<a[i]<<" ";
    //cout<<endl;
    Node *root3=new Node(5);
    root3->left=new Node(3);
    root3->left->left=new Node(6);
    
    //print_inorder(root1);
    cout<<balanced(root3);
    return 0;
}

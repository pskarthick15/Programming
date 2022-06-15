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

bool deadend(Node*root,int lower,int upper)
{
    if(!root)
        return false;
    else if(lower==upper)   
        return true;
    else
        return deadend(root->left,lower,root->data-1) || deadend(root->right,root->data+1,upper);
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(8);
    root1->left=new Node(5);
    root1->right=new Node(9);
    root1->left->left=new Node(2);
    root1->left->left->left=new Node(1);
    root1->left->right=new Node(7);
    if(deadend(root1,1,INT_MAX))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

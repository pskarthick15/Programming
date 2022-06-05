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

void leftview(Node *root,int level,vector<int>&arr)
{
    if(root==NULL)
        return;
    if(level==arr.size())
        arr.push_back(root->data);
    leftview(root->left,level+1,arr);
    leftview(root->right,level+1,arr);
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
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->left->left->right=new Node(8);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);
    vector<int>arr;
    leftview(root1,0,arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    //print_inorder(root1);
    return 0;
}

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

vector<int> morrisinorder(Node*root)
{
    vector<int>inorder;
    Node*curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            Node*prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr)
                prev=prev->right;
            if(prev->right==NULL) //Point of creating the thread to go back to root of the subtree of the last node or leaf node of the subtree.
            {
                prev->right=curr;
                curr=curr->left;
            }
            else //As it is left root and right, at the time of removing the thread after visiting the left subtree only print the root and then go to right. For preorder while creating the thread only traverse the root then others same.
            {
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;
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
    vector<int>morris=morrisinorder(root1);
    for(int i=0;i<morris.size();i++)
        cout<<morris[i]<<" ";
    return 0;
}

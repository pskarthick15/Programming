// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct tree
{
    int data;
    tree*left;
    tree*right;
    tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
}Tree;

typedef struct node
{
    int data;
    node*next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
}Node;



bool ispath(Tree*root,Node*head) {
        if(root->data==head->data)
        {
            if(head->next==NULL)
                return true;
            else
            {
                bool a,b;
                if(head==NULL ||root==NULL)
                    return false;
                if(root->left)
                {
                    if(root->left->data==head->next->data)
                    {
                        a=ispath(root->left,head->next);
                    }
                }
                if(root->right)
                {
                    if(root->right->data==head->next->data)
                    {
                        b=ispath(root->right,head->next);
                    }
                }
                return a || b;
            }
        }
        else
        {
            return (ispath(root->left,head) || ispath(root->right,head));
        }
    }



int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Tree*root=new Tree(1);
    root->left=new Tree(4);
    root->right=new Tree(4);
    root->left->right=new Tree(2);
    root->left->right->left=new Tree(1);
    root->right->left=new Tree(2);
    root->right->left->left=new Tree(6);
    root->right->left->right=new Tree(8);
    root->right->left->right->left=new Tree(1);
    root->right->left->right->right=new Tree(3);
    
    
    Node*head=new Node(1);
    head->next=new Node(4);
    head->next->next=new Node(2);
    head->next->next->next=new Node(6);
    head->next->next->next->next=new Node(8);
    cout<<ispath(root,head);
    
    return 0;
}

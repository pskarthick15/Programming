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

void print_size(Node*root,int &size)
{
    if(root==NULL)
        return;
    else
    {
        print_size(root->left,size);
        size+=1;
        print_size(root->right,size);
    }
}
void findmedian(Node*root,int &counter,int size,int &median)
{
    if(root==NULL)
        return;
    else
    {
        findmedian(root->left,counter,size,median);
        counter++;
        if(size%2!=0)
        {
            if(counter==(size+1)/2)
            {
                median=root->data;
            }
        }
        else
        {
            if(counter==size/2 || counter==size/2 + 1)
            {
                median+=root->data;
            }
                
        }
        findmedian(root->right,counter,size,median);
    }
}

int median(Node*root)
{
    int size=0,median=0,counter=0;
    print_size(root,size);
    findmedian(root,counter,size,median);
    if(size%2==0)
        median=median/2;
    return median;
}


int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(20);
    root1->left=new Node(8);
    root1->right=new Node(22);
    root1->left->left=new Node(4);
    root1->left->right=new Node(12);
    root1->left->right->left=new Node(10);
    root1->left->right->right=new Node(14);
    
    Node *root2=new Node(6);
    root2->left=new Node(3);
    root2->right=new Node(8);
    root2->left->left=new Node(1);
    root2->left->right=new Node(4);
    root2->right->left=new Node(7);
    
    cout<<median(root1)<<"\n"<<median(root2);
    return 0;
}

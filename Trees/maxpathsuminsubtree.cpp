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


int maxpathsubtree(Node*node,int &maxi)
{
    if(node==NULL)  
        return 0;
    int leftsum=maxpathsubtree(node->left,maxi);
    int rightsum=maxpathsubtree(node->right,maxi);
    maxi=max(maxi,node->data+leftsum+rightsum);
    return node->data+max(leftsum,rightsum);
}


int maxpathsum(Node*root)
{
    int maxi=0;
    int t=maxpathsubtree(root,maxi);
    return maxi;
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
    Node *root1=new Node(4);
    root1->left=new Node(2);
    root1->right=new Node(5);
    root1->left->left=new Node(7);
    root1->left->right=new Node(1);
    root1->left->right->left=new Node(6);
    root1->right->left=new Node(2);
    root1->right->right=new Node(3);
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);
    
    cout<<maxpathsum(root1)<<endl;
    cout<<maxpathsum(root2)<<endl;
    
    return 0;
}

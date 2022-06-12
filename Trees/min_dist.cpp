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

Node* LCA(Node*root,int n1,int n2)
{
    if(root==NULL || root->data==n1 ||root->data==n2)
        return root;
    else
    {
        Node*l=LCA(root->left,n1,n2);
        Node*r=LCA(root->right,n1,n2);
        if(l && r)  
            return root;
        else if(l)
            return l;
        else if(r)
            return r;
        else
            return NULL;
    }
}

int min_dist(Node*root,int node1,int node2)
{
    int d=0,d1,d2;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)//Taking level order elements batchwise to process!!
        {
            Node*node=q.front();
            if(node->data==node1)
                d1=d;
            else if(node->data==node2)
                d2=d;
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            
        }
        d++;
    }
    return d1+d2;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node *root1=new Node(5);
    root1->left=new Node(2);
    root1->left->left=new Node(3);
    root1->left->right=new Node(4);
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    
    int n1=3,n2=4,n3=2,n4=3;
    Node*lca1=LCA(root1,n1,n2);
    Node*lca2=LCA(root2,n3,n4);
    cout<<lca1->data<<" "<<lca2->data<<endl;
    cout<<min_dist(lca2,n3,n4);
    return 0;
}

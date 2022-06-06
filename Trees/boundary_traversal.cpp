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


void left_boundary(Node*root,vector<int>&ans)
{
    if(root==NULL)
        return;
    else
    {
        Node*node=root;
        while(node->left!=NULL || node->right!=NULL)
        {
            ans.push_back(node->data);
            if(node->left)
                node=node->left;
            else if(node->right)
                node=node->right;
        }
    }
}

void leaf_traversal(Node*root,vector<int>&ans)
{
    if(root==NULL)
        return;
    else if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    else
    {
        if(root->left)
            leaf_traversal(root->left,ans);
        if(root->right)
            leaf_traversal(root->right,ans);
    }
}

void reverse_rightboundary(Node*root,vector<int>&ans)
{
    if(root==NULL)
        return;
    else
    {
        Node*node=root->right;
        stack<int>s;
        while(node->left!=NULL || node->right!=NULL)
        {
            s.push(node->data);
            if(node->right)
                node=node->right;
            else if(node->left)
                node=node->left;
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
    }
    
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!"
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(7);
    root2->left->left=new Node(3);
    root2->left->left->right=new Node(4);
    root2->left->left->right->left=new Node(5);
    root2->left->left->right->right=new Node(6);
    root2->right->right=new Node(8);
    root2->right->right->left=new Node(9);
    root2->right->right->left->left=new Node(10);
    root2->right->right->left->right=new Node(11);
    vector<int>a;
    left_boundary(root2,a);
    leaf_traversal(root2,a);
    reverse_rightboundary(root2,a);
    
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

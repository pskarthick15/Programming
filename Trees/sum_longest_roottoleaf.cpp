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


pair<int,int> sum_longestpath(Node*root,int level,int sum)
{
    if(root==NULL)
    {
        return make_pair(level,sum);
    }
    else
    {
        pair<int,int>le;
        pair<int,int>ri;
        le=sum_longestpath(root->left,level+1,sum+root->data);
        ri=sum_longestpath(root->right,level+1,sum+root->data);
        if(le.first==ri.first)
        {
            if(le.second>ri.second)
                return le;
            else
                return ri;
        }
        else
        {
            if(le.first>ri.first)
                return le;
            else
                return ri;
        }
    }
}

int sumOfLongRootToLeafPath(Node *root)
{
    pair<int,int>ans=sum_longestpath(root,0,0);
    return ans.second;
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
    
    cout<<sumOfLongRootToLeafPath(root1)<<endl;
    cout<<sumOfLongRootToLeafPath(root2)<<endl;
    
    return 0;
}

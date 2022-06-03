// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node*left,*right;
    node(int val)
    {
        data=val;
        left=NULL,right=NULL;
    }
}Node;

    
void level_order(Node *root)
{
    vector<int>level;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* k=q.front();
        level.push_back(k->data);
        q.pop();
        if(k->left!=NULL)
            q.push(k->left);
        if(k->right!=NULL)  
            q.push(k->right);
    }
    for(int i=0;i<level.size();i++)
    {
        cout<<level[i]<<" ";
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(10);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    root->left->right->right=new Node(7);
    level_order(root);
    return 0;
}
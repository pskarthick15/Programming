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


vector<int> diagonal_traversal(Node*root)
{
    vector<int>a;
    if(root==NULL)
        return a;
    else
    {
        queue<Node*>q;
        Node*node=root;
        q.push(root);
        while(!q.empty())
        {
            Node*node=q.front();
            q.pop();
            while(node)
            {
                if(node->left)
                {
                    q.push(node->left);
                }
                a.push_back(node->data);
                node=node->right;
            }
        }
        return a;
    }
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!"
    
    Node *root2=new Node(8);
    root2->left=new Node(3);
    root2->right=new Node(10);
    root2->left->left=new Node(1);
    root2->right->left=new Node(6);
    root2->right->left->left=new Node(4);
    root2->right->left->right=new Node(7);
    root2->right->right=new Node(14);
    root2->right->right->left=new Node(13);
    vector<int>a=diagonal_traversal(root2);
    
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

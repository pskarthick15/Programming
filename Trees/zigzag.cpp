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


vector<int>zigzag(Node*root)
{
    vector<int>a;
    if(root==NULL)
        return a;
    else
    {
        vector<vector<int>>res;
        queue<Node*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                int index;
                if(flag==false)
                {
                    index=i;
                }
                else
                    index=size-i-1;
                row[index]=node->data;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            flag=!flag;
            res.push_back(row);
        }
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                a.push_back(res[i][j]);
            }
        }
        return a;
    }
}



int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
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
    vector<int>a=zigzag(root2);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    //print_inorder(root1);
    return 0;
}

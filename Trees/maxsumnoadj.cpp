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


pair<int,int> maxsumnoadj(Node*root,int sum1,int sum2,int flag)
{
    if(root==NULL)
        return make_pair(sum1,sum2);
    else if(root->left==NULL && root->right==NULL)
    {
        pair<int,int>take,nottake;
        if(flag==0)
        {
            nottake=make_pair(sum1,sum2);
            sum1+=root->data;
            take=make_pair(sum1,sum2);
            if(take.first>nottake.first)
                return take;
            else
                return nottake;
        }
        else if(flag==1)
        {
            nottake=make_pair(sum1,sum2);
            sum2+=root->data;
            take=make_pair(sum1,sum2);
            if(take.second>nottake.second)
                return take;
            else
                return nottake;
        }
    }
    else
    {
        pair<int,int>gc1,gc2,gc3,gc4,c1,c2;
        if(flag==0)
        {
            gc1=maxsumnoadj(root->left->left,sum1+root->data,sum2,0);
            gc2=maxsumnoadj(root->left->right,sum1+root->data,sum2,0);
            gc3=maxsumnoadj(root->right->left,sum1+root->data,sum2,0);
            gc4=maxsumnoadj(root->right->right,sum1+root->data,sum2,0);
            c1=maxsumnoadj(root->left,sum1,sum2,1);
            c2=maxsumnoadj(root->right,sum1,sum2,1);
            if(gc1.first>gc2.first && gc1.first>gc3.first && gc1.first>gc4.first && gc1.first>c1.first && gc1.first>c2.first)
                return gc1;
            else if(gc2.first>gc1.first && gc2.first>gc3.first && gc2.first>gc4.first && gc2.first>c1.first && gc2.first>c2.first)
                return gc2;
            else if(gc3.first>gc1.first && gc3.first>gc2.first && gc3.first>gc4.first && gc3.first>c1.first && gc3.first>c2.first)
                return gc3;
            else if(gc4.first>gc1.first && gc4.first>gc2.first && gc4.first>gc3.first && gc4.first>c1.first && gc4.first>c2.first)
                return gc4;
            else if(c1.first>gc1.first && c1.first>gc2.first && c1.first>gc3.first && c1.first>gc4.first && c1.first>c2.first)
                return c1;
            else
                return c2;
        }
        else if(flag==1)
        {
            gc1=maxsumnoadj(root->left->left,sum1,sum2+root->data,1);
            gc2=maxsumnoadj(root->left->right,sum1,sum2+root->data,1);
            gc3=maxsumnoadj(root->right->left,sum1,sum2+root->data,1);
            gc4=maxsumnoadj(root->right->right,sum1,sum2+root->data,1);
            c1=maxsumnoadj(root->left,sum1,sum2,0);
            c2=maxsumnoadj(root->right,sum1,sum2,0);
            
            if(gc1.second>gc2.second && gc1.second>gc3.second && gc1.second>gc4.second && gc1.second>c1.second && gc1.second>c2.second)
                return gc1;
            else if(gc2.second>gc1.second && gc2.second>gc3.second && gc2.second>gc4.second && gc2.second>c1.second && gc2.second>c2.second)
                return gc2;
            else if(gc3.second>gc1.second && gc3.second>gc2.second && gc3.second>gc4.second && gc3.second>c1.second && gc3.second>c2.second)
                return gc3;
            else if(gc4.second>gc1.second && gc4.second>gc2.second && gc4.second>gc3.second && gc4.second>c1.second && gc4.second>c2.second)
                return gc4;
            else if(c1.second>gc1.second && c1.second>gc2.second && c1.second>gc3.second && c1.second>gc4.second && c1.second>c2.second)
                return c1;
            else
                return c2;
        }
    }
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
    Node *root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->left->left=new Node(1);
    root1->right->left=new Node(4);
    root1->right->right=new Node(5);
    pair<int,int>maxi=maxsumnoadj(root1,0,0,0);
    if(maxi.first>maxi.second)
        cout<<maxi.first;
    else
        cout<<maxi.second;
    return 0;
}

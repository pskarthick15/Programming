typedef struct Node
{
  int val;
  struct Node*left,*right;
}TreeNode;


void preorder(TreeNode*root1,TreeNode*root2,int level)
    {
        if(root1==NULL || root2==NULL)
        {
            return;
        }
        if(level%2==0)
        {
            swap(root1->val,root2->val);
        }
        preorder(root1->left,root2->right,level+1);
        preorder(root1->right,root2->left,level+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        preorder(root->left,root->right,0);
        return root;
    }

int main()
{
  TreeNode*root=new TreeNode(2);
  root->left=new TreeNode(3);
  root->right=new TreeNode(5);
  root->left->left=new TreeNode(8);
  root->left->right=new TreeNode(13);
  root->right->left=new TreeNode(21);
  root->right->right=new TreeNode(34);
}

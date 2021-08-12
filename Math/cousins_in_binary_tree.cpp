class Solution {
public:

TreeNode* par1=new TreeNode();
 TreeNode* par2=new TreeNode();
int d1,d2;
// here d1 and d2 are height till the node x and y and par is for parent 
void help(TreeNode* root, TreeNode* parent, int depth,int x,int y){
    if(root==NULL)
        return ;
    if(root->val==x){
        par1=parent;
        d1=depth;
    }
      if(root->val==y){
        par2=parent;
        d2=depth;
    }
    help(root->left,root,depth+1,x,y);
    help(root->right,root,depth+1,x,y);
    return ;
}

bool isCousins(TreeNode* root, int x, int y) {
    help(root,NULL,0,x,y);  
    if(d1==d2&& par1!=par2)
        return true;
    else
        return false;
}
};
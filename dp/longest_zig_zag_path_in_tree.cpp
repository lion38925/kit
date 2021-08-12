/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        
        int i,ans=0;
        if(!root)
            return 0;
        solv(root->left,1,1,ans);       // start from top root with direction value
        solv(root->right,1,0,ans);
        
        return ans;
        
    }
    
    void solv(TreeNode* root, int val, int direction, int& ans){
        
        if(!root)
            return ;
        int k=0;
        if(direction==1){       // if the direction is left then we can continue and go to right or start new and go to left with new value
           solv(root->right,val+1,!direction,ans);
           solv(root->left,1,1,ans);
 
        }else
            if(direction==0){
               solv(root->left,val+1,!direction,ans); 
               solv(root->right,1,0,ans);
            }
        
       if(ans<val)
            ans = val;
        
        return ;
    }
};
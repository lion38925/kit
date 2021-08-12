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
    int findSecondMinimumValue(TreeNode* root) {
        
        if(!root)
            return -1;
        
        int k =-1,ans=-1;
        fs(root,k,ans);
        
        return ans;
        
    }
    
    void fs(TreeNode* root, int& k, int& ans){
        
        if(!root)
            return;
        
        fs(root->left,k,ans);
        fs(root->right,k,ans);
        
        if(k==-1)
            k = root->val;
        else
            if(ans==-1&&k!=root->val)
                ans = root->val;
        else{
            if(k>root->val){
                ans = k; 
                k = root->val;
            }else
                if(ans>root->val&&k!=root->val)
                    ans = root->val;
        }
        
        return ;
    }
};
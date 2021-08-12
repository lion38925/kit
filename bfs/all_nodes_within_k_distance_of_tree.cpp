/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        
        int i,j,k,l,m,n;
        
        vector<int>v;
        getTarget(target,K,v);
        gdis(root,target,K,v);
        
        return v;
    }
    
    void getTarget(TreeNode* target ,int k ,vector<int>& v){
        
        if(!target)
            return ;
        
        if(k==0){
            v.push_back(target->val);
            return;
        }
        
        getTarget(target->left,k-1,v);
        getTarget(target->right,k-1,v);
        
        return;
            
    }
    
    int gdis(TreeNode* root, TreeNode* target, int K, vector<int>& v){
        
        if(!root)
            return -1;
        
        if(root->val==target->val){
            return 0;
        }
        
        int dl = gdis(root->left,target, K,v);
        
        if(dl!=-1){
            if(dl+1==K){
                v.push_back(root->val);
            }
            else
                getTarget(root->right,K-dl-2,v);    
            
            return 1+dl;
            
        }
        
        int dr = gdis(root->right,target, K,v);
        
        if(dr!=-1){
            if(dr+1==K){
                v.push_back(root->val);
            }
            else
                getTarget(root->left,K-dr-2,v);    
            
            return 1+dr;
            
        }
        
        return -1;
    }
};
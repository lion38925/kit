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
    int maxLevelSum(TreeNode* root) {
        
        
        int l=0,ma=INT_MIN,c,i;
        
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        i=1;
        
        while(!q.empty()){
            
            c = q.size();
            
            int s=0;
            
            while(c--){
                
            TreeNode* temp;
            temp = q.front();
            q.pop();
            
            s+=temp->val;
                
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
            }
            
            if(s>ma){
                ma = s;
                l= i;
            }
            i++;
            
        }
        
        return l;
    }
};
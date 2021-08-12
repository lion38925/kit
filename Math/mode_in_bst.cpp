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
    TreeNode* pre = NULL;
    int curCnt = 1;
    int maxCnt = 1;
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
    
    void inOrder(TreeNode* root, vector<int>& res){
        if (!root) return;
        inOrder(root->left, res);
        if (pre) {
            if (root->val == pre->val) curCnt ++;
            else curCnt = 1;
        }
        pre = root;
        if (curCnt > maxCnt){
            maxCnt = curCnt;
            while (res.size()) res.pop_back();
            res.push_back(root->val);
        }
        else if (curCnt == maxCnt){
            res.push_back(root->val);
        }
        inOrder(root->right, res);
    }
};
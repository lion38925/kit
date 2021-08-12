class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        while(depth < d - 1){
            int qsize = que.size();
            for(int i = 0; i < qsize; i ++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left != NULL){
                    que.push(node->left);
                }
                if(node->right != NULL){
                    que.push(node->right);
                }
            }
            depth ++;
        }
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            TreeNode* temp = node->left;
            node->left = new TreeNode(v);
            node->left->left = temp;
            temp = node->right;
            node->right = new TreeNode(v);
            node->right->right = temp;
        }
        return root;
    }
};
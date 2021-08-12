
The basic idea is to hash the preorder traversal result (serialized to string)
 of every node (guaranteed to be unique for every possible tree shape, if null
  included). Everytime we get a match, we know we have a matching subtree. 
  To avoid adding the same subtree twice (for 3 or more matches), we use an
   unordered_map such that the value of the string key is true if the string
    has already been matched (added to answer vector).
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, bool> m;
        vector<TreeNode*> ans;
        preorder(m, ans, root);
        return ans;
    }
    string preorder(unordered_map<string, bool>& m, vector<TreeNode*>& ans, TreeNode* root) {
        if(!root) return ".";
        string s = to_string(root->val) + preorder(m, ans, root->left) + preorder(m, ans, root->right);
        auto it = m.find(s);
        if(it != m.end() && !it->second) {
            ans.emplace_back(root);
            m[s] = true;
        }
        else if(it == m.end()) m[s] = false;
        return s;
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
#include <iostream> 
using namespace std; 

// A binary Tree node 
struct node 
{ 
	int data; 
	struct node *left, *right; 
}; 

/* Recursive function to print all the nodes at distance k in the 
tree (or subtree) rooted with given root. See */
void printkdistanceNodeDown(node *root, int k) 
{ 
	// Base Case 
	if (root == NULL || k < 0) return; 

	// If we reach a k distant node, print it 
	if (k==0) 
	{ 
		cout << root->data << endl; 
		return; 
	} 

	// Recur for left and right subtrees 
	printkdistanceNodeDown(root->left, k-1); 
	printkdistanceNodeDown(root->right, k-1); 
} 

// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward. This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 
int printkdistanceNode(node* root, node* target , int k) 
{ 
	// Base Case 1: If tree is empty, return -1 
	if (root == NULL) return -1; 

	// If target is same as root. Use the downward function 
	// to print all nodes at distance k in subtree rooted with 
	// target or root 
	if (root == target) 
	{ 
		printkdistanceNodeDown(root, k); 
		return 0; 
	} 

	// Recur for left subtree 
	int dl = printkdistanceNode(root->left, target, k); 

	// Check if target node was found in left subtree 
	if (dl != -1) 
	{ 
		// If root is at distance k from target, print root 
		// Note that dl is Distance of root's left child from target 
		if (dl + 1 == k) 
			cout << root->data << endl; 

		// Else go to right subtree and print all k-dl-2 distant nodes 
		// Note that the right child is 2 edges away from left child 
		else
			printkdistanceNodeDown(root->right, k-dl-2); 

		// Add 1 to the distance and return value for parent calls 
		return 1 + dl; 
	} 

	// MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
	// Note that we reach here only when node was not found in left subtree 
	int dr = printkdistanceNode(root->right, target, k); 
	if (dr != -1) 
	{ 
		if (dr + 1 == k) 
			cout << root->data << endl; 
		else
			printkdistanceNodeDown(root->left, k-dr-2); 
		return 1 + dr; 
	} 

	// If target was neither present in left nor in right subtree 
	return -1; 
} 

// A utility function to create a new binary tree node 
node *newnode(int data) 
{ 
	node *temp = new node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us construct the tree shown in above diagram */
	node * root = newnode(20); 
	root->left = newnode(8); 
	root->right = newnode(22); 
	root->left->left = newnode(4); 
	root->left->right = newnode(12); 
	root->left->right->left = newnode(10); 
	root->left->right->right = newnode(14); 
	node * target = root->left->right; 
	printkdistanceNode(root, target, 2); 
	return 0; 
}


/// my code  


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
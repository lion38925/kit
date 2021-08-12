// C++ program to find the length of longest 
// path with same values in a binary tree. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to 
left child and a pointer to right child */
struct Node { 
int val; 
struct Node *left, *right; 
}; 

/* Function to print the longest path 
of same values */
int length(Node *node, int *ans) { 
if (!node) 
	return 0; 

// Recursive calls to check for subtrees 
int left = length(node->left, ans); 
int right = length(node->right, ans); 

// Variables to store maximum lengths in two directions 
int Leftmax = 0, Rightmax = 0; 

// If curr node and it's left child has same value 
if (node->left && node->left->val == node->val) 
	Leftmax += left + 1; 

// If curr node and it's right child has same value 
if (node->right && node->right->val == node->val) 
	Rightmax += right + 1; 
	
*ans = max(*ans, Leftmax + Rightmax); 
return max(Leftmax, Rightmax); 
} 

/* Driver function to find length of 
longest same value path*/
int longestSameValuePath(Node *root) { 
int ans = 0; 
length(root, &ans); 
return ans; 
} 

/* Helper function that allocates a 
new node with the given data and 
NULL left and right pointers. */
Node *newNode(int data) { 
Node *temp = new Node; 
temp->val = data; 
temp->left = temp->right = NULL; 
return temp; 
} 

// Driver code 
int main() { 
/* Let us construct a Binary Tree 
		4 
	/ \ 
	4 4 
	/ \ \ 
	4 9 5 */

Node *root = NULL; 
root = newNode(4); 
root->left = newNode(4); 
root->right = newNode(4); 
root->left->left = newNode(4); 
root->left->right = newNode(9); 
root->right->right = newNode(5); 
cout << longestSameValuePath(root); 
return 0; 
} 

// my code

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
    int longestUnivaluePath(TreeNode* root) {
        
        int i,ans=0;
        
        if(!root)
            return 0;
        
        i = lp(root,ans);
        return ans-1<0?0:ans-1;
    }
    
    int lp(TreeNode* root ,int& ans){
        if(!root)
            return 0;
        
        int k=-1,flag=0;
        int l = lp(root->left,ans);
        
        int h = lp(root->right,ans);
       
        
        if(root->right&&root->left){
            if(root->val==root->right->val&&root->val==root->left->val){
                ans = max(ans,l+h+1);
                k = max(l,h)+1;
                flag=1;
            }
                
        }
        if(root->right&&flag==0){
                if(root->val==root->right->val){
                    ans = max(ans,h+1);
                    k = h+1;
                    flag=1;
                }
                 
            }
        
        if(root->left&&flag==0){
                if(root->val==root->left->val){
                    ans = max(ans,l+1);
                    k = l+1;
                }
                
            }
        return k==-1?1:k;
            
        
        
    }
};
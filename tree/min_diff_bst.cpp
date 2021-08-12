// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
	
// Node of the binary tree 
struct node { 
	int data; 
	node* left; 
	node* right; 
	node(int data) 
	{ 
		this->data = data; 
		left = NULL; 
		right = NULL; 
	} 
}; 
	
// Function for in-order traversal of the tree 
void inorder(node* curr, node*& prev, int& ans) 
{ 
	
	// Base-case 
	if (curr == NULL) 
		return; 
	
	// Calling in-order on the left sub-tree 
	inorder(curr->left, prev, ans); 
	
	if (prev != NULL) 
		ans = min(curr->data - prev->data, ans); 
	prev = curr; 
	
	// Calling in-order on the right sub-tree 
	inorder(curr->right, prev, ans); 
} 
	
// Function to return the minimum 
// difference between any two nodes 
// of the given binary search tree 
int minDiff(node* root) 
{ 
	
	// Pointer to previous node in the 
	// in-order traversal of the BST 
	node* prev = NULL; 
	
	// To store the final ans 
	int ans = INT_MAX; 
	
	// Call in-order for the BST 
	inorder(root, prev, ans); 
	
	// Returning the final answer 
	return ans; 
} 
	
// Driver code 
int main() 
{ 
	node* root = new node(5); 
	root->left = new node(3); 
	root->right = new node(7); 
	root->left->left = new node(2); 
	root->left->right = new node(4); 
	root->right->left = new node(6); 
	root->right->right = new node(8); 
	
	cout << minDiff(root); 
	
	return 0; 
} 

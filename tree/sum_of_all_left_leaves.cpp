// A C++ program to find sum of all left leaves 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree Node has key, pointer to left and right 
children */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointer. */
Node *newNode(char k) 
{ 
	Node *node = new Node; 
	node->key = k; 
	node->right = node->left = NULL; 
	return node; 
} 

// A utility function to check if a given node is leaf or not 
bool isLeaf(Node *node) 
{ 
if (node == NULL) 
	return false; 
if (node->left == NULL && node->right == NULL) 
	return true; 
return false; 
} 

// This function returns sum of all left leaves in a given 
// binary tree 
int leftLeavesSum(Node *root) 
{ 
	// Initialize result 
	int res = 0; 

	// Update result if root is not NULL 
	if (root != NULL) 
	{ 
	// If left of root is NULL, then add key of 
	// left child 
	if (isLeaf(root->left)) 
			res += root->left->key; 
	else // Else recur for left child of root 
			res += leftLeavesSum(root->left); 				// instead of returning res pass is as & see below code

	// Recur for right child of root and update res 
	res += leftLeavesSum(root->right); 
	} 

	// return result 
	return res; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	// Let us a construct the Binary Tree 
	struct Node *root		 = newNode(20); 
	root->left			 = newNode(9); 
	root->right			 = newNode(49); 
	root->right->left		 = newNode(23); 
	root->right->right	 = newNode(52); 
	root->right->right->left = newNode(50); 
	root->left->left		 = newNode(5); 
	root->left->right		 = newNode(12); 
	root->left->right->right = newNode(12); 
	cout << "Sum of left leaves is "
		<< leftLeavesSum(root); 
	return 0; 
}
// A C++ program to find sum of all left leaves 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree Node has key, pointer to left and right 
children */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointer. */
Node *newNode(char k) 
{ 
	Node *node = new Node; 
	node->key = k; 
	node->right = node->left = NULL; 
	return node; 
} 

// A utility function to check if a given node is leaf or not 
bool isLeaf(Node *node) 
{ 
if (node == NULL) 
	return false; 
if (node->left == NULL && node->right == NULL) 
	return true; 
return false; 
} 

// This function returns sum of all left leaves in a given 
// binary tree 
void leftLeavesSum(Node *root, int &res) 
{ 
	// Initialize result 
	//int res = 0; 

	// Update result if root is not NULL 
	if (root != NULL) 
	{ 
	// If left of root is NULL, then add key of 
	// left child 
	if (isLeaf(root->left)) 
			res += root->left->key; 
	else // Else recur for left child of root 
			leftLeavesSum(root->left,res); 

	// Recur for right child of root and update res 
	leftLeavesSum(root->right,res); 
	} 

	// return result 
	return ; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	// Let us a construct the Binary Tree 
	struct Node *root		 = newNode(20); 
	root->left			 = newNode(9); 
	root->right			 = newNode(49); 
	root->right->left		 = newNode(23); 
	root->right->right	 = newNode(52); 
	root->right->right->left = newNode(50); 
	root->left->left		 = newNode(5); 
	root->left->right		 = newNode(12); 
	root->left->right->right = newNode(12); 
	int res=0;
	cout << "Sum of left leaves is ";
		leftLeavesSum(root,res); 
		cout<<res;
	return 0; 
}

// C++ implementation of a O(n) time method for 
// Zigzag order traversal 
#include <iostream> 
#include <stack> 
using namespace std; 

// Binary Tree node 
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 

// function to print the zigzag traversal 
int findheight(struct Node* root) 
{ 
	// if null then return 
	if (!root) 
		return 0;

    return max(findheight(root->left),findheight(root->right))+1; 

	
} 

// A utility function to create a new node 
struct Node* newNode(int data) 
{ 
	struct Node* node = new struct Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// driver program to test the above function 
int main() 
{ 
	// create tree 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(7); 
	root->left->right = newNode(6); 
	root->right->left = newNode(5); 
	root->right->right = newNode(4); 
	cout << "maximum height is"<<"\n";

	cout<<findheight(root); 

	return 0; 
} 

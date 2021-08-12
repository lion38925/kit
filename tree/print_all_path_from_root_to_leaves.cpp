#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
}; 

/* Prototypes for funtions needed in printPaths() */
void printPathsRecur(node* node, int path[], int pathLen); 
void printArray(int ints[], int len); 

/*Given a binary tree, print out all of its root-to-leaf 
paths, one per line. Uses a recursive helper to do the work.*/


/* Recursive helper function -- given a node, 
and an array containing the path from the root 
node up to but not including this node, 
print out all the root-leaf paths.*/
void printPathsRecur(node* node, vector<int> &v) 
{ 
	if (node == NULL) 
		return; 
	
	/* append this node to the path array */
    v.push_back(node->data);
	
	/* it's a leaf, so print the path that led to here */
	if (node->left == NULL && node->right == NULL) 
	{ 
    	for (int i=0; i<v.size(); i++) 
			cout << v[i] << " "; 
		cout<<"\n";
	} 
	else
	{ 
		/* otherwise try both subtrees */
		printPathsRecur(node->left, v); 
		printPathsRecur(node->right,v);
	} 
	 v.pop_back();
} 

void printPaths(node* node) 
{ 
	//int path[1000]; 
    vector<int> path; 
	printPathsRecur(node,path); 
} 



/* utility that allocates a new node with the 
given data and NULL left and right pointers. */
node* newnode(int data) 
{ 
	node* Node = new node(); 
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 
	
	return(Node); 
} 

/* Driver code*/
int main() 
{ 
	
	/* Constructed binary tree is 
				10 
			/ \ 
			8 2 
		/ \ / 
		3 5 2 
	*/
	node *root = newnode(10); 
	root->left = newnode(8); 
	root->right = newnode(2); 
	root->left->left = newnode(3); 
	root->left->right = newnode(5); 
	root->right->left = newnode(2); 
	
	printPaths(root); 
	return 0; 
} 

// This code is contributed by rathbhupendra 

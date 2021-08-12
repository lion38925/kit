// CPP code for inorder succesor 
// and predecessor of tree 
#include<iostream> 
#include<stdlib.h> 

using namespace std; 

struct Node 
{ 
	int data; 
	Node* left,*right; 
}; 

// Function to return data 
Node* getnode(int info) 
{ 
	Node* p = (Node*)malloc(sizeof(Node)); 
	p->data = info; 
	p->right = NULL; 
	p->left = NULL; 
	return p; 
} 

/* 
since inorder traversal results in 
ascending order visit to node , we 
can store the values of the largest 
no which is smaller than a (predecessor) 
and smallest no which is large than 
a (succesor) using inorder traversal 
*/
void find_p_s(Node* root,int a,
			Node** p, Node** q)
{
	// If root is null return 
	if(!root)
		return ;

	// traverse the left subtree	 
	find_p_s(root->left, a, p, q);

	// store the first greater node in q during inorder traversal
	if(root->data > a && !*q)
	{
        *q = root;
	}
	// store all the smaller nodes in p during inorder traversal.
    // last smaller node refers to inorder predecessor
	else if(root->data < a)
	{
		*p = root;
	}

	// traverse the right subtree
	find_p_s(root->right, a, p, q);
}

// Driver code 
int main() 
{ 
	Node* root1 = getnode(50); 
	root1->left = getnode(20); 
	root1->right = getnode(60); 
	root1->left->left = getnode(10); 
	root1->left->right = getnode(30); 
	root1->right->left = getnode(55); 
	root1->right->right = getnode(70); 
	Node* p = NULL, *q = NULL; 

	find_p_s(root1, 70, &p, &q); 
	
	if(p) 
		cout << p->data; 
    else
        cout << "NULL";
	if(q) 
		cout << " " << q->data; 
    else
      	cout << " NULL";
	return 0; 
} 

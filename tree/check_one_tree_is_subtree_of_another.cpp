#include <cstring> 
#include <iostream> 
using namespace std; 
#define MAX 100 

// Structure of a tree node 
struct Node { 
	char key; 
	struct Node *left, *right; 
}; 

// A utility function to create a new BST node 
Node* newNode(char item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to store inorder traversal of tree rooted 
// with root in an array arr[]. Note that i is passed as reference 
void storeInorder(Node* root, char arr[], int& i) 
{ 
	if (root == NULL) { 
		arr[i++] = '$'; 
		return; 
	} 
	storeInorder(root->left, arr, i); 
	arr[i++] = root->key; 
	storeInorder(root->right, arr, i); 
} 

// A utility function to store preorder traversal of tree rooted 
// with root in an array arr[]. Note that i is passed as reference 
void storePreOrder(Node* root, char arr[], int& i) 
{ 
	if (root == NULL) { 
		arr[i++] = '$'; 
		return; 
	} 
	arr[i++] = root->key; 
	storePreOrder(root->left, arr, i); 
	storePreOrder(root->right, arr, i); 
} 

/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S) 
{ 
	/* base cases */
	if (S == NULL) 
		return true; 
	if (T == NULL) 
		return false; 

	// Store Inorder traversals of T and S in inT[0..m-1] 
	// and inS[0..n-1] respectively 
	int m = 0, n = 0; 
	char inT[MAX], inS[MAX]; 
	storeInorder(T, inT, m); 
	storeInorder(S, inS, n); 
	inT[m] = '\0', inS[n] = '\0'; 

	// If inS[] is not a substring of preS[], return false 
	if (strstr(inT, inS) == NULL) 
		return false; 

	// Store Preorder traversals of T and S in inT[0..m-1] 
	// and inS[0..n-1] respectively 
	m = 0, n = 0; 
	char preT[MAX], preS[MAX]; 
	storePreOrder(T, preT, m); 
	storePreOrder(S, preS, n); 
	preT[m] = '\0', preS[n] = '\0'; 

	// If inS[] is not a substring of preS[], return false 
	// Else return true 
	return (strstr(preT, preS) != NULL); 
} 

// Driver program to test above function 
int main() 
{ 
	Node* T = newNode('a'); 
	T->left = newNode('b'); 
	T->right = newNode('d'); 
	T->left->left = newNode('c'); 
	T->right->right = newNode('e'); 

	Node* S = newNode('a'); 
	S->left = newNode('b'); 
	S->left->left = newNode('c'); 
	S->right = newNode('d'); 

	if (isSubtree(T, S)) 
		cout << "Yes: S is a subtree of T"; 
	else
		cout << "No: S is NOT a subtree of T"; 

	return 0; 
} 


// my solution

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
    string sp,si,tp,ti;
        
    int i,j,k,l,m;
    
    si.clear();
    ti.clear();
    gi(s,si);
    gi(t,ti);

    if(strstr(si.c_str(),ti.c_str())==NULL)
        return false;
    
    sp.clear();
    tp.clear();
        // above we use char arr[] and here we are using string so strstr only works for char arr[]  so
		// we need to convert it to char type using " c_str "
    gp(s,sp);
    gp(t,tp);
        
    if(strstr(sp.c_str(),tp.c_str())==NULL)		// converting and checking 
        return false;
        
    return true;
    }
    
    void gi(TreeNode* root, string& v){
        if(!root){
           v+="^";
            return;
        }
        gi(root->left,v);
        v+=to_string(root->val);
        gi(root->right,v);
        
        return;
    }
    
    void gp(TreeNode* root, string& v){
        if(!root){
            v+="^";
            return;
        }
        v+=to_string(root->val);
        gp(root->left,v);
        
        gp(root->right,v);
        
        return;
    }
};


// another solution


class Solution {
public:
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) 
            return true;
        if((s && t) && (s->val == t->val) && 
           isSame(s->left, t->left) &&  isSame(s->right, t->right))
            return true;
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if (isSame(s, t)) 
            return true;
        return isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }
};
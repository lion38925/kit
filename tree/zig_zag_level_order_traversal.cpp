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
void zizagtraversal(struct Node* root) 
{ 
	// if null then return 
	if (!root) 
		return; 

	// declare two stacks 
	stack<struct Node*> currentlevel; 
	stack<struct Node*> nextlevel; 

	// push the root 
	currentlevel.push(root); 

	// check if stack is empty 
	//bool lefttoright = true; 
	while (!currentlevel.empty()||!nextlevel.empty()){
	    cout<<"\n";
        while(!currentlevel.empty()){
            struct Node* temp =currentlevel.top();
            cout<<temp->data<<" ";
            currentlevel.pop();
            if (temp->left) 
                    nextlevel.push(temp->left); 
            if (temp->right) 
                    nextlevel.push(temp->right); 
            
        }
        cout<<"\n";
        while(!nextlevel.empty()){
            struct Node* temp = nextlevel.top();
            cout<<temp->data<<" ";
            nextlevel.pop();
            if (temp->right) 
                    currentlevel.push(temp->right); 
            if (temp->left) 
                    currentlevel.push(temp->left); 
            
        }  

		
	} 
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
	cout << "ZigZag Order traversal of binary tree is \n"; 

	zizagtraversal(root); 

	return 0; 
} 

/// my code

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int count;
         queue<TreeNode*>q;
        vector<vector<int>> res;
        if(root)
            q.push(root);
        else
            return res;
        
        while(!q.empty()){
            count = q.size();
            vector<int>temp;
            while(count>0){
                
                TreeNode* qn;
                qn = q.front();
                q.pop();
                temp.push_back(qn->val);
                if(qn->left)
                    q.push(qn->left);
                if(qn->right)
                    q.push(qn->right);
                count--;
            }
            res.push_back(temp);
        }
        
        for(count = 1;count<res.size();count++){
            if(count%2!=0){
                reverse(res[count].begin(),res[count].end());
            }
            
        }
        return res;
    }
};
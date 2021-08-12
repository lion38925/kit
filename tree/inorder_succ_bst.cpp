#include <bits/stdc++.h> 
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
      
   
}; 
  
  struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void iop(struct Node* root,int target,int &k) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if(root==NULL)
        return;
    
    iop(root->left,target,k);
    
    if(root->data==target)
        k=1;
    if(root->data!=target&&root!=NULL&&k==1)
        {
            cout<<root->data;
            k=0;
        }
    iop(root->right,target,k);
    
} 
  


struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct Node *root = NULL; 
    root = insert(root, 20); 
    insert(root, 8); 
    insert(root, 4); 
    insert(root, 12); 
    insert(root, 10); 
    insert(root, 14); 
    insert(root, 22); 
    int k=0;
    iop(root,14,k);
    
  
  
    return 0; 
} 
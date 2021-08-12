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
bool isbst(struct Node* root, struct Node* &Prev)       // insted of this & we can also use static  static node *prev = NULL;  
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if(root==NULL)
        return true;
    
    if(!isbst(root->left,Prev)){
        return false;
    }
    
    if(Prev!=NULL){
        if(root->data<=Prev->data){
            //cout<<"NOT BST";
            return false;
        }
       
    }
    Prev= root;
    
   return isbst(root->right,Prev);
    
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
    root = newNode(4);  
    root->left = newNode(2);  
    root->right = newNode(5);  
    root->left->left = newNode(1);  
    root->left->right = newNode(3); 
    // root = insert(root, 20); 
    // insert(root, 8); 
    // insert(root, 4); 
    // insert(root, 12); 
    // insert(root, 10); 
    // insert(root, 14); 
    // insert(root, 22); 
    struct Node *Prev = NULL;
    if(isbst(root,Prev)){
        cout<<"BST";
    }else{
        cout<<"NOT BST";
    }
    
  
  
    return 0; 
} 
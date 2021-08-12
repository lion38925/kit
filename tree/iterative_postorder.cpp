
// Iterative function to perform post-order traversal of the tree
void postorderIterative(Node* root)
{
    // create an empty stack and push root node
    stack<Node*> stk;
    stk.push(root);
 
    // create another stack to store post-order traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!stk.empty())
    {
        // we pop a node from the stack and push the data to output stack
        Node *curr = stk.top();
        stk.pop();
 
        out.push(curr->data);
 
        // push left and right child of popped node to the stack
        if (curr->left)
            stk.push(curr->left);
 
        if (curr->right)
            stk.push(curr->right);
    }
 
    // print post-order traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}





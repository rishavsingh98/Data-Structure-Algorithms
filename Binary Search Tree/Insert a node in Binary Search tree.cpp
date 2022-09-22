/*
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.

Example 1:
Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
*/
Node* insert(Node* root, int key)
{
    Node *curr = root, *newNode = new Node(key);
    
    while(true)
    {
        if(curr->data == key)
            return root;
        else if(curr->data > key)
            if(!curr->left)
            {
                curr->left = newNode;
                return root;
            }
            else
                curr = curr->left;
        else
            if(!curr->right)
            {
                curr->right = newNode;
                return root;
            }
            else
                curr = curr->right;
    }
}

/*
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:
Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
*/
Node* LCA(Node *root, int n1, int n2)
{
    if (!root)
        return root;
    
    if(n1 > root->data and n2 > root->data)
        return LCA(root->right, n1, n2);
    
    if(n1 < root->data and n2 < root->data)
        return LCA(root->left, n1, n2);
    
	return root;
}

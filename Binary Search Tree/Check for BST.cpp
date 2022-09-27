/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
   2
 /    \
1      3
Output: 1 
*/
class Solution
{
    public:
    bool isBSTUtil(Node *root, int minrange, int maxrange)
    {
        if(!root)
            return true;
            
        else if(root->data >= minrange and root->data <= maxrange)
        {
            int maxrangeLeft = root->data;
            int minrangeRight = root->data;
            
            return isBSTUtil(root->left, minrange, maxrangeLeft) and isBSTUtil(root->right, minrangeRight, maxrange);
        }
        else
            return  false;
    }
    bool isBST(Node* root) 
    {
        int minrange = INT_MIN, maxrange = INT_MAX;
        return isBSTUtil(root, minrange, maxrange);
    }
};

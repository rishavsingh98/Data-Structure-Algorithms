/*
Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.
Examples :
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                   \
     2        1                     4 
*/
void getInorder(Node* root, vector<Node*>& inorder)
{
    if(!root)
        return;
    getInorder(root->left, inorder);
    inorder.push_back(root);
    getInorder(root->right, inorder);
    return;
}

Node* balancedBST(int start, int end, vector<Node*>& inorder)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end)/2;
    Node *root = inorder[mid];
    root->left = balancedBST(start, mid-1, inorder);
    root->right = balancedBST(mid+1, end, inorder);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<Node*> inorder;
	getInorder(root, inorder);
	return balancedBST(0, inorder.size()-1, inorder);
}

/* 
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.
 

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []
 
Constraints:
1. The number of nodes in the tree is in the range [0, 104].
2. -10^5 <= Node.val <= 10^5
3. Each node has a unique value.
4. root is a valid binary search tree.
5. -10^5 <= key <= 10^5
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        else if(root->val == key)
        {
            TreeNode* temp = root,*par;
            if(!root->left and !root->right)
                return NULL;
            else if(!root->left)
            {
                par = temp;
                temp = temp->right;
                if(temp->left)
                {
                    temp = temp->left;
                    par = par->right;
                }
                while(temp->left)
                {   
                    par = par->left;
                    temp = temp->left;
                }
                if(root == par)
                    par->right = temp->right;
                else
                    par->left = temp->right;
                root->val = temp->val;
            }
            else
            {
                par = temp;
                temp = temp->left;
                if(temp->right)
                {
                    temp = temp->right;
                    par = par->left;
                }
                while(temp->right)
                {   
                    par = par->right;
                    temp = temp->right;
                }
                if(root == par)
                    par->left = temp->left;
                else
                    par->right = temp->left;
                root->val = temp->val;
                
            }
        }
        else if(root->val > key)
            root->left = deleteNode(root->left,key);
        else
            root->right = deleteNode(root->right,key);
        return root;
    }
};
